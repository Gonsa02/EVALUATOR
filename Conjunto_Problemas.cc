#include "Conjunto_Problemas.hh"

void Conjunto_Problemas::anadir(const string& id_p, const Problema &p)
{
    conj_p.emplace(make_pair(id_p, p)); 
}

void Conjunto_Problemas::apuntar(const string &id_p)
{
    map<string,Problema>::iterator it = conj_p.find(id_p);
    iterador = it;
}

void Conjunto_Problemas::incrementar_envios_totales_problema()
{
    iterador -> second.incrementar_envios_totales();
}

void Conjunto_Problemas::incrementar_envios_exitosos_problema()
{
    iterador -> second.incrementar_envios_exitosos();
}

int Conjunto_Problemas::tamano() const
{
    return conj_p.size();
}

bool Conjunto_Problemas::existe(const string& id)
{
    map<string,Problema>::iterator it = conj_p.find(id);
    if (it != conj_p.end()) {
	iterador = it;
	return true;
    }
    else return false;
}

void Conjunto_Problemas::inicializar()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	string id;
	cin >> id;
	Problema p(id);
	conj_p.emplace(make_pair(id, p));
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

void Conjunto_Problemas::escribir_problema() const
{
    iterador -> second.escribir_problema();
}
