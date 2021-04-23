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

// Falta implementar este método
bool Curso::existe_interseccion() const
{
   return true; 
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
