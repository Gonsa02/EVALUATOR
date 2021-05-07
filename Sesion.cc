#include "Sesion.hh"
#include "BinTree.hh"
#include <string>

string Sesion::obtener_id() const
{
    return id;
}

string Sesion::problema_inicial() const
{
    return prerequisitos.value();
}

bool Sesion::interseccion_vacia(const Sesion& s) const
{
    set<string>::const_iterator const_it = conj_id_problemas.begin(); 
    set<string>::const_iterator aux_const_it = s.conj_id_problemas.begin(); 
    while (const_it != conj_id_problemas.end() and aux_const_it != s.conj_id_problemas.end()) {
	if (*const_it == *aux_const_it) return false;
	else if (*const_it < *aux_const_it) ++const_it;
	else ++aux_const_it;
    }
    return true;
}

bool Sesion::contiene_problema(string id) const
{
    set<string>::const_iterator const_it = conj_id_problemas.find(id);
    if (const_it == conj_id_problemas.end()) return false;
    else return true;
}

void Sesion::problemas_enviables(Usuario &u) const
{
    problemas_enviables_i(prerequisitos, u);
}

void Sesion::problemas_envio(Usuario &u, string id_problema) const
{
    BinTree<string> a = prerequisitos;
    bool found = false;
    problemas_envio_i(a, u, id_problema, found);
}

void Sesion::escribir_sesion() const
{
    cout << id << ' ' << conj_id_problemas.size() << ' ';
    escribir_postorden(prerequisitos);
    cout << endl;
}

void Sesion::leer()
{
    string id;
    BinTree<string> b;
    set<string> conj_p;
    cin >> id;
    this -> id = id;
    leer_bin_tree(b, conj_p, "0");
    prerequisitos = b;
    conj_id_problemas = conj_p;

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

void Sesion::leer_bin_tree(BinTree<string>& a, set<string>& conj_p, string marca)
{
  string x;
  cin >> x;
  if (x!=marca){
	conj_p.insert(x);
	BinTree<string> l;
	leer_bin_tree(l, conj_p, marca);
	BinTree<string> r;
	leer_bin_tree(r, conj_p, marca);
	a=BinTree<string>(x,l,r);
  }
}

bool Sesion::operator<(const Sesion &s) const
{
    return id < s.obtener_id();
}

void Sesion::inizializar_iterador()
{
    iterador_problemas = conj_id_problemas.begin();
}

void Sesion::incrementar_iterador()
{
    ++iterador_problemas;
}

bool Sesion::end() const
{
    return iterador_problemas == conj_id_problemas.end();
}

string Sesion::valor() const
{
    return *iterador_problemas;
}

void Sesion::problemas_envio_i(const BinTree<string>& a, Usuario& u, string id_problema, bool& found) const

{
    if (not a.empty() and not found) {
	if (id_problema == a.value()) {
	    found = true;
	    problemas_enviables_i(a.left(), u);
	    problemas_enviables_i(a.right(), u);
	}
	else {
	    problemas_envio_i(a.left(), u, id_problema, found);
	    problemas_envio_i(a.right(), u, id_problema, found);
	}
    }
}

void Sesion::problemas_enviables_i(const BinTree<string>& a, Usuario& u) const
{
    if (not a.empty()) {
	if (not u.problema_resuelto(a.value())) u.anadir_problema_enviable(a.value());
	else {
	    problemas_enviables_i(a.left(), u);
	    problemas_enviables_i(a.right(), u);
	}
    }
}
