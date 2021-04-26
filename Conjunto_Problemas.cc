#include "Conjunto_Problemas.hh"

void Conjunto_Problemas::anadir(const Problema &p)
{
    conj_p.insert(make_pair(p.obtener_id(), p)); 
}

void Conjunto_Problemas::actualizar(const Problema &p)
{
    conj_p[p.obtener_id()] = p;
}

int Conjunto_Problemas::tamano() const
{
    return conj_p.size();
}

bool Conjunto_Problemas::existe(Problema &p)
{
    map<string,Problema>::const_iterator const_it = conj_p.find(p.obtener_id());
    if (const_it != conj_p.end()) {
	p = const_it -> second;
	return true;
    }
    else return false;
}

void Conjunto_Problemas::obtener(const string &id_problema, Problema &p)
{
    p = conj_p[id_problema];
}

void Conjunto_Problemas::inicializar()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	Problema p;
	p.leer();
	conj_p.insert(make_pair(p.obtener_id(), p));
    }
}

void Conjunto_Problemas::listar() const
{
    set<Problema> aux;
    for (map<string, Problema>::const_iterator const_it = conj_p.begin(); const_it != conj_p.end(); ++const_it)
	aux.insert(const_it -> second);
    for (set<Problema>::const_iterator const_it = aux.begin(); const_it != aux.end(); ++const_it)
	const_it -> escribir_problema();
}
