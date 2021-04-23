#include "Conjunto_Cursos.hh"

void Conjunto_Cursos::añadir(const Curso &c)
{
    conj_c.insert(make_pair(c.obtener_id(), c));
}

void Conjunto_Cursos::actualizar(const Curso& c)
{
    map<int, Curso>::iterator it = conj_c.find(c.obtener_id());
    it -> second = c;
}

bool Conjunto_Cursos::existe(Curso &c)
{
    map<int, Curso>::const_iterator const_it = conj_c.find(c.obtener_id());
    if (const_it != conj_c.end()) {
	c = const_it -> second;
	return true;
    }
    else return false;
}

void Conjunto_Cursos::obtener_con_id(int id, Curso &c)
{
    map<int, Curso>::const_iterator const_it = conj_c.find(id);
    c = const_it -> second;
}

void Conjunto_Cursos::inicializar()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	Curso c;
	c.leer();
	conj_c.insert(make_pair(c.obtener_id(), c));
    }
}

void Conjunto_Cursos::listar() const
{
    for (map<int, Curso>::const_iterator const_it = conj_c.begin(); const_it != conj_c.end(); ++const_it)
	const_it -> second.escribir_curso();
}
