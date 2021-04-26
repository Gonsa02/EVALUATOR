#include "Sesion.hh"
#include "BinTree.hh"

string Sesion::obtener_id() const
{
    return id;
}

int Sesion::numero_problemas() const
{
    return num_problemas;
}

string Sesion::problema_inicial() const
{
    return prerequisitos.value();
}

vector<string> Sesion::problemas_sucesores(string id_problema)
{
    vector<string> sucesores(0);
    BinTree<string> sub = subarbol(prerequisitos, id_problema);
    if (not sub.empty() and not sub.left().empty()) sucesores.push_back(sub.left().value());
    if (not sub.empty() and not sub.right().empty()) sucesores.push_back(sub.right().value());
    return sucesores;
}

bool Sesion::interseccion_vacia(const Sesion& s) const
{
    set<string> s_aux = s.conj_id_problemas;
    for (set<string>::const_iterator const_it = conj_id_problemas.begin(); const_it != conj_id_problemas.end(); ++const_it) {
	set<string>::const_iterator it_aux = s_aux.find(*const_it);
	if (it_aux != s_aux.end()) return false;
    }
    return true;
}

bool Sesion::contine_problema(string id) const
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

int Sesion::calcular_nodos(BinTree<string> b)
{
    if (not b.empty()) return 1 + calcular_nodos(b.left()) + calcular_nodos(b.right());
    return 0;
}

BinTree<string> Sesion::subarbol(const BinTree<string>& arbol, string id_problema) const
{
    if (arbol.value() == id_problema) return arbol;
    BinTree<string> left;
    BinTree<string> right;
    if (not arbol.left().empty()) left = subarbol(arbol.left(), id_problema);
    if (not arbol.right().empty()) right = subarbol(arbol.right(), id_problema);
    if (not left.empty()) return left;
    if (not right.empty()) return right;
    BinTree<string> empty;
    return empty;
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
