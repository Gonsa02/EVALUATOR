#include "Usuario.hh"

Usuario::Usuario(string nombre)
{
    this -> nombre = nombre;
    id_curso_inscrito = 0;
    intentos_problemas = 0;
    envios_totales = 0;
    inscrito = false;
}

Usuario::~Usuario(){}

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

list<string> Usuario::problemas_resueltos_curso_acutal() const
{
    return pro_resueltos_curso_actual;
}

list<string> Usuario::problemas_resueltos() const
{
    return pro_resueltos;
}

list<string> Usuario::problemas_enviables() const
{
    return pro_enviables;
}

bool Usuario::cumple_requisitos(string id_problema) const
{
    bool found = false;
    list<string>::const_iterator const_it = pro_enviables.begin();
    while (not found and const_it != problemas_enviables().end()) {
	if (*const_it == id_problema) found = true;
	++const_it;
    }
    return found;
}

void Usuario::escribir_usuario() const
{
    cout << envios_totales << " " << problemas_resueltos().size() << " " << intentos_problemas << " " << id_curso_inscrito << endl;
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
