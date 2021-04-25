#include "Usuario.hh"

void Usuario::incrementar_intentos_problemas()
{
    ++intentos_problemas;
}

void Usuario::incrementar_envios_totales()
{
    ++envios_totales;
}

void Usuario::inscribir_a_curso(int id_curso)
{
    id_curso_inscrito = id_curso;
    inscrito = true;
}

void Usuario::finalizar_curso()
{
    id_curso_inscrito = 0;
    inscrito = false;
    pro_resueltos_curso_actual.clear();
}

string Usuario::obtener_nombre() const
{
    return nombre;
}

int Usuario::num_intentos_problemas() const
{
  return intentos_problemas;  
}

int Usuario::num_problemas_correctos() const
{
    return pro_resueltos.size();
}

int Usuario::num_problemas_enviables() const
{
    return pro_enviables.size();
}

int Usuario::num_envios_totales() const
{
    return envios_totales;
}

bool Usuario::inscrito_a_curso() const
{
    return inscrito;
}

int Usuario::curso() const
{
    return id_curso_inscrito;
}

bool Usuario::cumple_requisitos(string id_problema) const
{
    set<string>::const_iterator const_it = pro_enviables.find(id_problema);
    if (const_it != pro_enviables.end()) return true;
    else return false;
}

bool Usuario::problema_intentado(string id_problema) const
{
    set<string>::const_iterator const_it = pro_intentados.find(id_problema);
    if (const_it == pro_intentados.end()) return false;
    else return true;
}

void Usuario::escribir_usuario() const
{
    cout << envios_totales << " " << pro_resueltos.size() << " " << intentos_problemas << " " << id_curso_inscrito << endl;
}

void Usuario::escribir_problemas_enviables() const
{
    for (set<string>::const_iterator const_it = pro_enviables.begin(); const_it != pro_enviables.end(); ++const_it)
	cout << *const_it << " ";
}

void Usuario::escribir_problemas_resueltos() const
{
    for (set<string>::const_iterator const_it = pro_resueltos.begin(); const_it != pro_resueltos.end(); ++const_it)
	cout << *const_it << " ";
}

void Usuario::leer()
{
    string n;
    cin >> n;
    nombre = n;
    intentos_problemas = 0;
    envios_totales = 0;
    id_curso_inscrito = -1;
    inscrito = false;
}

void Usuario::añadir_problema_correcto(string id_problema)
{
    pro_resueltos.insert(id_problema);
    pro_resueltos_curso_actual.insert(id_problema);
    pro_enviables.erase(id_problema);
    pro_intentados.insert(id_problema);
}

void Usuario::añadir_problema_enviable(string id_problema)
{
    pro_enviables.insert(id_problema);
}

void Usuario::quitar_problema_enviable(string id_problema)
{
    pro_enviables.erase(id_problema);
}

void Usuario::añadir_problema_intentado(string id_problema)
{
    pro_intentados.insert(id_problema);
}
