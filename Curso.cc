#include "Curso.hh"

void Curso::usuario_inscribir_curso()
{
    ++usuarios_cursando_curso;
}

void Curso::usuario_dar_baja_curso()
{
    --usuarios_cursando_curso;
}

void Curso::usuario_finaliza_curso()
{
   ++usuarios_curso_completado;
   --usuarios_cursando_curso;
}

int Curso::obtener_id() const
{
    return id;
}

int Curso::usuarios_curso_complteado() const
{
    return usuarios_curso_completado;
}

int Curso::usuarios_actuales() const
{
    return usuarios_cursando_curso;
}

int Curso::numero_sesiones() const
{
    return conj_s.size();
}

bool Curso::contiene_problema(string ID) const
{
    for (set<Sesion>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it)
	if (const_it -> contine_problema(ID)) return true;
    return false;
}

bool Curso::existe_interseccion() const
{
    for (int i = 0; i <= conj_s.size(); ++i) {
	set<Sesion>::const_iterator const_it = conj_s.begin();
	for (set<Sesion>::const_iterator aux_it = conj_s.begin(); aux_it != conj_s.end(); ++aux_it) {
	    if (const_it != aux_it) {
		if (not const_it -> interseccion_vacia(*aux_it)) return true;
	    }
	}
	++const_it;
    }
    return false;
}

string Curso::sesion_problema(string ID) const
{
    bool found = false;
    set<Sesion>::const_iterator const_it = conj_s.begin();
    while (not found and const_it != conj_s.end()) {
	if (const_it -> contine_problema(ID)) found = true;
	else ++const_it;
    }
    return const_it -> obtener_id();
}

vector<string> Curso::problemas_iniciales() const
{
    vector<string> v;
    for (set<Sesion>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it)
	v.push_back(const_it -> problema_inicial());
    return v;
}

void Curso::escribir_sesiones() const
{
    for (int i = 0; i < id_sesiones.size(); ++i) cout << id_sesiones[i] << " ";
    cout << endl;
}

void Curso::escribir_curso() const
{
    cout << usuarios_curso_completado << " " << usuarios_curso_completado << " " << id_sesiones.size();
    escribir_sesiones();
}

void Curso::leer()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
	Sesion s;
	s.leer();
	conj_s.insert(s);
	v.push_back(s.obtener_id());
    }
}

void Curso::leer_id()
{
    int id;
    cin >> id;
    this -> id = id;
}
