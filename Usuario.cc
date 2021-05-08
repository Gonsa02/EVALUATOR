#include "Usuario.hh"

void Usuario::incrementar_envios_totales()
{
    ++envios_totales;
}

void Usuario::incrementar_problemas_intentados()
{
    ++problemas_intentados;
}

void Usuario::inscribir_a_curso(const int& id_curso)
{
    inscrito = true;
    id_curso_inscrito = id_curso;
}

void Usuario::finalizar_curso()
{
    id_curso_inscrito = 0;
    inscrito = false;
}

void Usuario::obtener_nombre(string& name) const
{
    name = nombre;
}

int Usuario::num_problemas_enviables() const
{
    return pro_enviables.size();
}

bool Usuario::inscrito_a_curso() const
{
    return inscrito;
}

int Usuario::curso() const
{
    return id_curso_inscrito;
}

bool Usuario::cumple_requisitos(const string& id_problema) const
{
    map<string,int>::const_iterator const_it = pro_enviables.find(id_problema);
    if (const_it != pro_enviables.end()) return true;
    else return false;
}

bool Usuario::problema_resuelto(const string& id_problema) const
{
    map<string,int>::const_iterator const_it = pro_resueltos.find(id_problema);
    if (const_it == pro_resueltos.end()) return false;
    else return true;
}

bool Usuario::problema_intentado(const string& id_problema) const
{
    return  0 < pro_enviables.find(id_problema) -> second;
}

void Usuario::escribir_usuario() const
{
    cout << nombre<< '(' << envios_totales << "," << pro_resueltos.size() << "," << problemas_intentados << "," << id_curso_inscrito << ')' << endl;
}

void Usuario::escribir_problemas_enviables() const
{
    for (map<string,int>::const_iterator const_it = pro_enviables.begin(); const_it != pro_enviables.end(); ++const_it)
	cout << const_it -> first << '(' << const_it -> second << ')' << endl;
}

void Usuario::escribir_problemas_resueltos() const
{
    for (map<string,int>::const_iterator const_it = pro_resueltos.begin(); const_it != pro_resueltos.end(); ++const_it)
	cout << const_it -> first << '(' << const_it -> second << ')' << endl;
}

void Usuario::leer()
{
    string n;
    cin >> n;
    nombre = n;
    envios_totales = 0;
    id_curso_inscrito = 0;
    problemas_intentados = 0;
    inscrito = false;
}

void Usuario::anadir_problema_correcto(const string& id_problema)
{
    pro_resueltos.emplace(make_pair(id_problema, pro_enviables.find(id_problema) -> second));
    pro_enviables.erase(id_problema);
}

void Usuario::anadir_problema_enviable(const string& id_problema)
{
    pro_enviables.emplace(make_pair(id_problema, 0));
}

void Usuario::anadir_intento_problema(const string& id_problema)
{
    map<string,int>::iterator it = pro_enviables.find(id_problema);
    if (it -> second == 0) ++problemas_intentados;
    it -> second++;
    ++envios_totales;
}
