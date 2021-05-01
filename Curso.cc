#include "Curso.hh"
#include "Conjunto_Sesiones.hh"

Curso::Curso()
{
   id = 0;
   usuarios_curso_completado = 0;
   usuarios_cursando_curso = 0;
}

void Curso::anadir_id(int id)
{
    this -> id = id;
}

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

int Curso::usuarios_actuales() const
{
    return usuarios_cursando_curso;
}

bool Curso::contiene_problema(string ID) const
{
    for (set<Sesion>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it) {
	if (const_it -> contiene_problema(ID)) return true;
    }
    return false;
}

bool Curso::existe_interseccion() const
{
    for (set<Sesion>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it) {
	for (set<Sesion>::const_iterator aux_it = const_it; aux_it != conj_s.end(); ++aux_it) {
	    if (const_it != aux_it and not const_it -> interseccion_vacia(*aux_it)) return true;
	}
    }
    return false;
}

void Curso::sesion_problema(string ID, Sesion& s) const
{
    bool found = false;
    set<Sesion>::const_iterator const_it = conj_s.begin();
    while (not found and const_it != conj_s.end()) {
	if (const_it -> contiene_problema(ID)) found = true;
	else ++const_it;
    }
    s = *const_it;
}

void Curso::problemas_iniciales(vector<string>& v) const
{
    for (set<Sesion>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it)
	v.push_back(const_it -> problema_inicial());
}

void Curso::escribir_sesiones() const
{
    bool space = false;
    for (int i = 0; i < id_conj_s.size(); ++i) {
	if (space) cout << ' ';
	else space = true;
	cout << id_conj_s[i];
    }
}

void Curso::escribir_curso() const
{
    cout << id << " " << usuarios_curso_completado << " " << usuarios_cursando_curso << " " << conj_s.size() << " (";
    escribir_sesiones();
    cout << ')' << endl;
}

void Curso::leer(const Conjunto_Sesiones& conjunto_sesiones)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	string id_s;
	cin >> id_s;
	Sesion s;
	conjunto_sesiones.obtener_con_id(id_s, s);
	conj_s.insert(s);
	id_conj_s.push_back(id_s);
    }
}

void Curso::leer_id()
{
    int id;
    cin >> id;
    this -> id = id;
}
