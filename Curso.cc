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

bool Curso::contiene_problema(string ID, Conjunto_Sesiones& conjunto_sesiones) const
{
    for (set<string>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it) {
	Sesion s;
	conjunto_sesiones.obtener_con_id(*const_it, s);
	if (s.contine_problema(ID)) return true;
    }
    return false;
}

bool Curso::existe_interseccion(Conjunto_Sesiones& conjunto_sesiones) const
{
    for (int i = 0; i/2 <= conj_s.size(); ++i) {
	set<string>::const_iterator const_it = conj_s.begin();
	Sesion s;
	conjunto_sesiones.obtener_con_id(*const_it, s);
	for (set<string>::const_iterator aux_it = conj_s.begin(); aux_it != conj_s.end(); ++aux_it) {
	    if (const_it != aux_it) {
		Sesion s_aux;
		conjunto_sesiones.obtener_con_id(*aux_it, s_aux);
		if (not s.interseccion_vacia(s_aux)) return true;
	    }
	}
	++const_it;
    }
    return false;
}

string Curso::sesion_problema(string ID, Conjunto_Sesiones& conjunto_sesiones) const
{
    bool found = false;
    set<string>::const_iterator const_it = conj_s.begin();
    while (not found and const_it != conj_s.end()) {
	Sesion s;
	conjunto_sesiones.obtener_con_id(*const_it, s);
	if (s.contine_problema(ID)) found = true;
	else ++const_it;
    }
    return *const_it;
}

vector<string> Curso::problemas_iniciales(Conjunto_Sesiones& conjunto_sesiones) const
{
    vector<string> v;
    for (set<string>::const_iterator const_it = conj_s.begin(); const_it != conj_s.end(); ++const_it) {
	Sesion s;
	conjunto_sesiones.obtener_con_id(*const_it, s);
	v.push_back(s.problema_inicial());
    }
    return v;
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

void Curso::leer()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	string id_s;
	cin >> id_s;
	conj_s.insert(id_s);
	id_conj_s.push_back(id_s);
    }
}

void Curso::leer_id()
{
    int id;
    cin >> id;
    this -> id = id;
}
