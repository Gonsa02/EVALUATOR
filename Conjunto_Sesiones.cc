#include "Conjunto_Sesiones.hh"

void Conjunto_Sesiones::añadir(const Sesion &s)
{
    conj_s.insert(make_pair(s.obtener_id(), s)); 
}

bool Conjunto_Sesiones::existe(Sesion &s)
{
    map<string,Sesion>::const_iterator const_it = conj_s.find(s.obtener_id());
    if (const_it != conj_s.end()) {
	s = const_it -> second;
	return true;
    }
    else return false;
}

void Conjunto_Sesiones::inicializar()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	Sesion s;
	s.leer();
	conj_s.insert(make_pair(s.obtener_id(), s));
    }
}

void Conjunto_Sesiones::listar() const
{
    for (map<string, Sesion>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it)
	const_it -> second.escribir_sesion();
}

void Conjunto_Sesiones::obtener_con_id(string id_sesion, Sesion &s)
{
    s = conj_s[id_sesion];
}
