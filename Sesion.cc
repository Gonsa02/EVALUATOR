#include "Sesion.hh"
#include "Conjunto_Usuarios.hh"

Sesion::Sesion(const string& id_s)
{
    id = id_s;
}

void Sesion::obtener_id(string& id_s) const
{
    id_s = id;
}

void Sesion::problemas_enviables(Conjunto_Usuarios& conj_u) const
{
    problemas_enviables_i(prerequisitos, conj_u);
}

void Sesion::problemas_envio(Conjunto_Usuarios& conj_u, const string& id_problema) const
{
    BinTree<string> a = prerequisitos;
    bool found = false;
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

void Sesion::leer_id()
{
    string id;
    cin >> id;
    this -> id = id;
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

void Sesion::problemas_envio_i(const BinTree<string>& a, Conjunto_Usuarios& conj_u, const string& id_problema, bool& found) const

{
    if (not a.empty() and not found) {
	if (id_problema == a.value()) {
	    found = true;
	    problemas_enviables_i(a.left(), conj_u);
	    problemas_enviables_i(a.right(), conj_u);
	}
	else {
	    problemas_envio_i(a.left(), conj_u, id_problema, found);
	    problemas_envio_i(a.right(), conj_u, id_problema, found);
	}
    }
}

void Sesion::problemas_enviables_i(const BinTree<string>& a, Conjunto_Usuarios& conj_u) const
{
    if (not a.empty()) {
	if (not conj_u.usuario_problema_resuelto(a.value())) conj_u.anadir_problema_enviable(a.value());
	else {
	    problemas_enviables_i(a.left(), conj_u);
	    problemas_enviables_i(a.right(), conj_u);
	}
    }
}

void Sesion::anadir_problemas_a_curso_i(const BinTree<string>& a, Curso& c) const
{
    if (not a.empty() and not c.existe_interseccion()) {
	c.anadir_problema_sesion(a.value(), id);
	anadir_problemas_a_curso_i(a.left(), c);
	anadir_problemas_a_curso_i(a.right(), c);
    }
}
