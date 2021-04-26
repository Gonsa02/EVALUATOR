#include "Conjunto_Usuarios.hh"

void Conjunto_Usuarios::anadir(const Usuario &u)
{
    conj_u.insert(make_pair(u.obtener_nombre(), u));
}

void Conjunto_Usuarios::borrar(const Usuario &u)
{
    conj_u.erase(u.obtener_nombre());
}

void Conjunto_Usuarios::actualizar(const Usuario &u)
{
    map<string, Usuario>::iterator it = conj_u.find(u.obtener_nombre());
    it -> second = u;
}

bool Conjunto_Usuarios::existe(Usuario &u)
{
    map<string, Usuario>::const_iterator const_it = conj_u.find(u.obtener_nombre());
    if (const_it != conj_u.end()) {
	u = const_it -> second;
	return true;
    }
    else return false;
}

void Conjunto_Usuarios::obtener(const string& nombre, Usuario &u)
{
    map<string, Usuario>::iterator it = conj_u.find(nombre);
    u = it -> second;
}

int Conjunto_Usuarios::numero_usuarios() const
{
    return conj_u.size();
}

void Conjunto_Usuarios::inicializar()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	Usuario u;
	u.leer();
	conj_u.insert(make_pair(u.obtener_nombre(), u));
    }
}

void Conjunto_Usuarios::listar() const
{
    for (map<string, Usuario>::const_iterator const_it = conj_u.begin(); const_it != conj_u.end(); ++const_it)
	const_it -> second.escribir_usuario();
}
