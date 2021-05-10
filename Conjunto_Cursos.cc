#include "Conjunto_Cursos.hh"
#include "Conjunto_Sesiones.hh"

void Conjunto_Cursos::anadir(Curso &c)
{
    c.anadir_id(conj_c.size()+1);
    int id;
    c.obtener_id(id);
    conj_c.emplace(make_pair(id, c));
}

void Conjunto_Cursos::actualizar(const Curso& c)
{
    int id;
    c.obtener_id(id);
    map<int,Curso>::iterator it = conj_c.find(id);
    it -> second = c;
}

void Conjunto_Cursos::usuario_baja_curso(const int& id_curso)
{
    conj_c.find(id_curso) -> second.usuario_dar_baja_curso();
}

void Conjunto_Cursos::inscribir_usuario_a_curso()
{
    iterador -> second.usuario_inscribir_curso();
}

void Conjunto_Cursos::curso_inizializar_iterador()
{
    iterador -> second.inizializar_iterador();
}

void Conjunto_Cursos::curso_incrementar_iterador()
{
    iterador -> second.incrementar_iterador();
}

void Conjunto_Cursos::apuntar(const int &id_p)
{
    map<int,Curso>::iterator it = conj_c.find(id_p);
    iterador = it;
}

void Conjunto_Cursos::usuario_finaliza_curso()
{
    iterador -> second.usuario_finaliza_curso();
}

bool Conjunto_Cursos::existe(const int& id)
{
    map<int,Curso>::iterator it = conj_c.find(id);
    if (it != conj_c.end()) {
	iterador = it;
	return true;
    }
    else return false;
}

void Conjunto_Cursos::obtener_con_id(const int& id, Curso &c)
{
    map<int, Curso>::const_iterator const_it = conj_c.find(id);
    c = const_it -> second;
}

int Conjunto_Cursos::tamano() const
{
    return conj_c.size();
}

bool Conjunto_Cursos::curso_end() const
{
    return iterador -> second.end();
}

void Conjunto_Cursos::curso_sesion_iterador(string &id_s) const
{
    iterador -> second.valor(id_s);
}

bool Conjunto_Cursos::curso_contiene_problema(const string &id_p, string &id_s) const
{
    return iterador -> second.contiene_problema(id_p, id_s);
}

int Conjunto_Cursos::usuarios_actuales_curso() const
{
    return iterador -> second.usuarios_actuales();
}

void Conjunto_Cursos::inicializar(Conjunto_Sesiones& conj_s)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	int id = conj_c.size()+1;
	Curso c(id);
	c.leer();
	c.inizializar_iterador();
	while (not c.end()) {
	    string id_s;
	    c.valor(id_s);
	    conj_s.apuntar(id_s);
	    conj_s.anadir_problemas_a_curso(c);
	    c.incrementar_iterador();
	}
	conj_c.emplace(make_pair(id, c));
    }
}

void Conjunto_Cursos::listar() const
{
    for (map<int, Curso>::const_iterator const_it = conj_c.begin(); const_it != conj_c.end(); ++const_it)
	const_it -> second.escribir_curso();
}

void Conjunto_Cursos::escribir_curso() const
{
    iterador -> second.escribir_curso();
}
