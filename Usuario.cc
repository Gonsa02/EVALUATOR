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
    list<string> l;
    pro_resueltos_curso_actual = l;
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
    bool found = false;
    list<string>::const_iterator const_it = pro_enviables.begin();
    while (not found and const_it != pro_enviables.end()) {
	if (*const_it == id_problema) found = true;
	++const_it;
    }
    return found;
}

void Usuario::escribir_usuario() const
{
    cout << envios_totales << " " << pro_resueltos.size() << " " << intentos_problemas << " " << id_curso_inscrito << endl;
}

void Usuario::escribir_problemas_enviables() const
{
    for (list<string>::const_iterator const_it = pro_enviables.begin(); const_it != pro_enviables.end(); ++const_it)
	cout << *const_it << " ";
}

void Usuario::escribir_problemas_resueltos() const
{
    for (list<string>::const_iterator const_it = pro_resueltos.begin(); const_it != pro_resueltos.end(); ++const_it)
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
    añadir_problema_a_lista(pro_resueltos, id_problema);
    añadir_problema_a_lista(pro_resueltos_curso_actual, id_problema);
    quitar_problema_a_lista(pro_enviables, id_problema);
}

void Usuario::añadir_problema_enviable(string id_problema)
{
    añadir_problema_a_lista(pro_enviables, id_problema);
}

void Usuario::añadir_problema_a_lista(list<string>& l, string id_problema) 
{
    list<string>::iterator it = l.begin();
    while (it != l.end() and *it < id_problema) ++it;
    l.insert(it, id_problema);
}

void Usuario::quitar_problema_a_lista(list<string>& l, string id_problema) 
{
    list<string>::iterator it = l.begin();
    while (it != l.end() and *it != id_problema) ++it;
    it = l.erase(it);
}
