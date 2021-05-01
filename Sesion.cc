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

int Sesion::problemas_sucesores(string id_problema, string& sucesor_1, string& sucesor_2) const 
{ 
    return problemas_sucesores_i(prerequisitos, id_problema, sucesor_1, sucesor_2);
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

int Sesion::problemas_sucesores_i(const BinTree<string>& a, string id_problema, string& sucesor_1, string& sucesor_2) const
{
    int n = -1;
    if (not a.empty()) {
	if (id_problema == a.value()) {
	    ++n;
	    if (a.left().empty()) {
		if (not a.right().empty()) {
		    sucesor_1 = a.right().value();
		    ++n;
		}
	    }
	    else {
		sucesor_1 = a.left().value();
		++n;
		if (not a.right().empty()) {
		    sucesor_2 = a.right().value();
		    ++n;
		}
	    }
	}
	else {
	    int l = problemas_sucesores_i(a.left(), id_problema, sucesor_1, sucesor_2);
	    if (l != -1) n = l;
	    else n = problemas_sucesores_i(a.right(), id_problema, sucesor_1, sucesor_2);
	}
    }
    return n;
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
