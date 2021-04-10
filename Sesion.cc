#include "Sesion.hh"
#include "BinTree.hh"

Sesion::Sesion(string id_sesion, BinTree<string> b)
{
    id = id_sesion;
    prerequisitos = b;
    num_problemas = calcular_nodos(b);
}

Sesion::~Sesion(){}

int Sesion::numero_problemas() const
{
    return num_problemas;
}


vector<string> Sesion::problemas_sucesores(string id_problema)
{
    vector<string> sucesores(0);
    BinTree<string> sub = subarbol(prerequisitos, id_problema);
    if (not sub.empty() and not sub.left().empty()) sucesores.push_back(sub.left().value());
    if (not sub.empty() and not sub.right().empty()) sucesores.push_back(sub.right().value());
    return sucesores;
}

void Sesion::escribir_sesion() const
{
    postorden(prerequisitos);
}

void Sesion::postorden(const BinTree<string> &arbol) const
{
    if (not arbol.empty()) {
	postorden(arbol.left());
	postorden(arbol.right());
	cout << arbol.value() << endl;
    }
}

int Sesion::calcular_nodos(BinTree<string> b)
{
    if (not b.empty()) return 1 + calcular_nodos(b.left()) + calcular_nodos(b.right());
    return 0;
}

BinTree<string> subarbol(BinTree<string> arbol, string id_problema)
{
    if (arbol.value() == id_problema) {
	return arbol;
    }
    BinTree<string> left;
    BinTree<string> right;
    if (not arbol.left().empty()) left = subarbol(arbol.left(), id_problema);
    if (not arbol.right().empty()) right = subarbol(arbol.right(), id_problema);
    if (not left.empty()) return left;
    if (not right.empty()) return right;
    BinTree<string> empty;
    return empty;
}
