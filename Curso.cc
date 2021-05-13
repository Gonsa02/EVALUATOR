#include "Curso.hh"

Curso::Curso()
{
    id = 0;
    usuarios_curso_completado = 0;
    usuarios_cursando_curso = 0;
    interseccion = false;
}

Curso::Curso(const int& id_c)
{
   id = id_c;
   usuarios_curso_completado = 0;
   usuarios_cursando_curso = 0;
   interseccion = false;
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

int Curso::usuarios_actuales() const
{
    return usuarios_cursando_curso;
}

bool Curso::contiene_problema(const string &id_p, string &id_s) const
{
    map<string,string>::const_iterator const_it = problema_sesion.find(id_p);
    if (const_it != problema_sesion.end()) {
	id_s = const_it -> second;
	return true;
    }
    else return false;
}

bool Curso::existe_interseccion() const
{
    return interseccion;
}

void Curso::sesion_problema(const string& ID, string& id_s) const
{
    id_s = problema_sesion.find(ID) -> second;
}

int Curso::tamano() const
{
    return id_conj_s.size();
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
    cout << id << " " << usuarios_curso_completado << " " << usuarios_cursando_curso << " " << id_conj_s.size() << " (";
    escribir_sesiones();
    cout << ')' << endl;
}

void Curso::leer()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    id_conj_s = v;
}

void Curso::anadir_problema_sesion(const string& id_problema, const string& id_sesion)
{
    // Hacemos el emplace y aprobechamos que este devuelve un par con un iterador y un booleano
    // que nos indica si ha sido insertado con exito, es decir si el valor es true, este no existía,
    // por lo tanto la intersección es la negación del valor que devuelve.
    interseccion = not problema_sesion.emplace(make_pair(id_problema, id_sesion)).second;
}

void Curso::inizializar_iterador()
{
   iterador = 0; 
}

void Curso::incrementar_iterador()
{
    ++iterador;
}

bool Curso::end() const
{
    return iterador == id_conj_s.size();
}

void Curso::valor(string& id_s) const
{
    id_s = id_conj_s[iterador];
}
