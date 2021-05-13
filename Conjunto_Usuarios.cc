#include "Conjunto_Usuarios.hh"

void Conjunto_Usuarios::anadir(const string& nombre)
{
    Usuario u(nombre);
    conj_u.emplace(make_pair(nombre, u));
}

void Conjunto_Usuarios::borrar()
{
    conj_u.erase(iterador);
}

void Conjunto_Usuarios::inscribir_usuario_a_curso(const int &id_c)
{
    iterador -> second.inscribir_a_curso(id_c);
}

void Conjunto_Usuarios::anadir_problema_enviable(const string &id_p)
{
    iterador -> second.anadir_problema_enviable(id_p);
}

void Conjunto_Usuarios::apuntar(const string &nombre)
{
    map<string,Usuario>::iterator it = conj_u.find(nombre);
    iterador = it;
}

void Conjunto_Usuarios::usuario_envio_problema(const string &id_p)
{
    iterador -> second.anadir_intento_problema(id_p);
}

void Conjunto_Usuarios::usuario_finaliza_curso()
{
    iterador -> second.finalizar_curso();
}

void Conjunto_Usuarios::usuario_problema_correcto(const string &id_p)
{
    iterador -> second.anadir_problema_correcto(id_p);
}

bool Conjunto_Usuarios::existe(const string& nombre)
{
    map<string,Usuario>::iterator it = conj_u.find(nombre);
    if (it != conj_u.end()) {
	iterador = it;
	return true;
    }
    else return false;
}

int Conjunto_Usuarios::numero_usuarios() const
{
    return conj_u.size();
}

bool Conjunto_Usuarios::usuario_inscrito_a_curso(int& id_c) const
{
    // Consultamos si el Usuario apuntado por el iterador esta inscrito a algun Curso.
    if (iterador -> second.inscrito_a_curso()) {
	id_c = iterador -> second.curso(); // Dejamos en id_c el identificador del Curso que está cursando.
	return true;
    }
    else return false;
}

void Conjunto_Usuarios::curso_usuario(int& id) const
{
   id = iterador -> second.curso(); 
}

bool Conjunto_Usuarios::usuario_problema_resuelto(const string &id_p) const
{
    return iterador -> second.problema_resuelto(id_p);
}

int Conjunto_Usuarios::num_problemas_enviables_usuario() const
{
    return iterador -> second.num_problemas_enviables();
}

void Conjunto_Usuarios::inicializar()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	string nombre;
	cin >> nombre;
	Usuario u(nombre);
	conj_u.emplace(make_pair(nombre, u));
    }
}

void Conjunto_Usuarios::listar() const
{
    for (map<string, Usuario>::const_iterator const_it = conj_u.begin(); const_it != conj_u.end(); ++const_it)
	const_it -> second.escribir_usuario();
}

void Conjunto_Usuarios::usuario_escribir_problemas_enviables() const
{
    iterador -> second.escribir_problemas_enviables();
}

void Conjunto_Usuarios::usuario_escribir_problemas_resueltos() const
{
    iterador -> second.escribir_problemas_resueltos();
}

void Conjunto_Usuarios::escribir_usuario() const
{
    iterador -> second.escribir_usuario();
}
