/** @file Conjunto_Sesiones.cc
    @brief Implementación de la clase Conjunto_Sesiones
*/
#include "Conjunto_Sesiones.hh"

void Conjunto_Sesiones::anadir(const string& id_s, const Sesion& s)
{
    conj_s.emplace(make_pair(id_s, s)); 
}

void Conjunto_Sesiones::apuntar(const string &id_s)
{
    map<string,Sesion>::const_iterator const_it = conj_s.find(id_s);
    iterador = const_it;
}

void Conjunto_Sesiones::anadir_problemas_a_curso(Curso &c) const
{
    iterador -> second.anadir_problemas_a_curso(c);
}

int Conjunto_Sesiones::tamano() const
{
    return conj_s.size();
}

void Conjunto_Sesiones::sesion_problemas_enviables_usuario(Conjunto_Usuarios &conj_u, const string &id_s) const
{
    map<string,Sesion>::const_iterator const_it = conj_s.find(id_s);
    const_it -> second.problemas_enviables(conj_u);
}

void Conjunto_Sesiones::sesion_problemas_envio_usuario(Conjunto_Usuarios &conj_u, const string &id_s, const string &id_p) const
{
    map<string,Sesion>::const_iterator const_it = conj_s.find(id_s);
    const_it -> second.problemas_envio(conj_u, id_p);
}

bool Conjunto_Sesiones::existe(const string& id_s)
{
    map<string,Sesion>::const_iterator const_it = conj_s.find(id_s);
    if (const_it != conj_s.end()) {
	iterador = const_it;
	return true;
    }
    else return false;
}

void Conjunto_Sesiones::inicializar()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	string id;
	cin >> id;
	Sesion s(id);
	s.leer(); // Lee la estructura de prerequisitos de la Sesion.
	conj_s.emplace(make_pair(id, s));
    }
}

void Conjunto_Sesiones::listar() const
{
    for (map<string, Sesion>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it)
	const_it -> second.escribir_sesion();
}

void Conjunto_Sesiones::escribir_sesion() const
{
    iterador -> second.escribir_sesion();
}
