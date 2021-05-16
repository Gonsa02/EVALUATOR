/** @file Sesion.cc
    @brief Implementación de la clase Sesion
*/

#include "Sesion.hh"
#include "Conjunto_Usuarios.hh"

Sesion::Sesion(const string& id_s)
{
    id = id_s;
}

// Todas las funciones que al final tienen _i son funciones de immersión que usamos
// para poder pasar el BinTree como parámetro.

void Sesion::problemas_enviables(Conjunto_Usuarios& conj_u) const
{
    obtener_problemas_enviables_i(prerequisitos, conj_u);
}

void Sesion::problemas_envio(Conjunto_Usuarios& conj_u, const string& id_problema) const
{
    BinTree<string> a = prerequisitos;
    bool found = false;
    // problemas_envio_i buscará el subarbol que tiene como raíz el problema con "id_problema" y a partir de ahí
    // llamará a una función que ira añadiendo los problemas no completados de un Usuario, el bool "found" se pasa
    // para poder cortar las llamadas recursivas una vez ya se ha encontrado el nodo con id_problema.
    problemas_envio_i(a, conj_u, id_problema, found);
}

void Sesion::anadir_problemas_a_curso(Curso &c) const
{
    anadir_problemas_a_curso_i(prerequisitos, c);
}

void Sesion::escribir_sesion() const
{
    cout << id << ' ' << num_problemas << ' ';
    escribir_postorden(prerequisitos);
    cout << endl;
}

void Sesion::leer()
{
    BinTree<string> b;
    int num = 0;
    leer_bin_tree(b, "0", num);
    prerequisitos = b;
    num_problemas = num;
}

void Sesion::escribir_postorden(const BinTree<string> &arbol) const
{
    if (not arbol.empty()) {
	cout << '(';
	escribir_postorden(arbol.left());
	escribir_postorden(arbol.right());
	cout << arbol.value() << ')';
    }
}

void Sesion::leer_bin_tree(BinTree<string>& a, const string& marca, int& num)
{
    // "marca" = string que indica que a partir de ese nodo ya no hay más hijos
  string x;
  cin >> x;
  if (x!=marca){
	BinTree<string> l;
	leer_bin_tree(l, marca, num);
	BinTree<string> r;
	leer_bin_tree(r, marca, num);
	a=BinTree<string>(x,l,r);
	++num;
  }
}

// La siguiente función busca el subárbol que tiene como raíz el identificador del Problema = "id_problema" y a partir de ahí
// llama a otra función que añade los problemas que el Usuario apuntado por el iterador del Conjunto_Usuarios aún no ha completado.
// Una vez hemos encontrado el nodo con id_problema ponemos el found = true y se cortan las llamadas recursivas.
void Sesion::problemas_envio_i(const BinTree<string>& a, Conjunto_Usuarios& conj_u, const string& id_problema, bool& found) const
{
    if (not a.empty() and not found) {
	if (id_problema == a.value()) {
	    found = true;
	    obtener_problemas_enviables_i(a.left(), conj_u);
	    obtener_problemas_enviables_i(a.right(), conj_u);
	}
	else {
	    problemas_envio_i(a.left(), conj_u, id_problema, found);
	    problemas_envio_i(a.right(), conj_u, id_problema, found);
	}
    }
}

// La siguiente función va añadiendo los problemas que se encuentran en la raíz de "a" en caso que el Usuario apuntado por
// el iterador del Conjunto_Usuarios no haya resuelto ese problema ya, en caso contrario se llama a la función con los hijos
// del problema ya resuelto.
void Sesion::obtener_problemas_enviables_i(const BinTree<string>& a, Conjunto_Usuarios& conj_u) const
{
    if (not a.empty()) {
	if (not conj_u.usuario_problema_resuelto(a.value())) conj_u.anadir_problema_enviable(a.value());
	else {
	    obtener_problemas_enviables_i(a.left(), conj_u);
	    obtener_problemas_enviables_i(a.right(), conj_u);
	}
    }
}

// La siguiente función va recorriendo el BinTree de la Sesion y va añadiendo los problemas al Curso "c"
// mientras no exista intersección, si existe intersección sabemos que el Curso no es valido y por lo tanto
// podemos parar de dejar de añadir problemas ya que el Curso "c" va a ser desechado y no se va ha añadir
// al repositorio de cursos.
void Sesion::anadir_problemas_a_curso_i(const BinTree<string>& a, Curso& c) const
{
    if (not a.empty() and not c.existe_interseccion()) {
	c.anadir_problema_sesion(a.value(), id);
	anadir_problemas_a_curso_i(a.left(), c);
	anadir_problemas_a_curso_i(a.right(), c);
    }
}
