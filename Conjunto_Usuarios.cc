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

void Conjunto_Usuarios::inscribir_usuario_a_curso(const Usuario &u, Curso &c, const Conjunto_Sesiones &conj_s)
{
    map<string, Usuario>::iterator it = conj_u.find(u.obtener_nombre());
    Usuario user = it -> second;
    user.inscribir_a_curso(c.obtener_id());
    c.inizializar_iterador();
    while (not c.end()) {
	string id_s = c.valor();
	Sesion s;
	conj_s.obtener_con_id(id_s, s);
	s.problemas_enviables(user);
	c.incrementar_iterador();
    }
    it -> second = user;
}

void Conjunto_Usuarios::envio_usuario(string nombre, string id_problema)
{
    map<string, Usuario>::iterator it = conj_u.find(nombre);
    Usuario u = it -> second;
    u.incrementar_envios_totales();
    u.anadir_intento_problema(id_problema);
    it -> second = u;
}

bool Conjunto_Usuarios::envio_correcto_usuario(string nombre, string id_problema, const Sesion &s)
{
    map<string, Usuario>::iterator it = conj_u.find(nombre);
    Usuario u = it -> second;
    u.anadir_problema_correcto(id_problema);
    u.quitar_problema_enviable(id_problema);
    s.problemas_envio(u, id_problema);
    bool curso_finalizado = false;
    if (u.num_problemas_enviables() == 0) {
	u.finalizar_curso();
	curso_finalizado = true;
    }
    it -> second = u;
    return curso_finalizado;
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
