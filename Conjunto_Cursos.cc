/** @file Conjunto_Cursos.cc
    @brief Implementación de la clase Conjunto_Cursos
*/

#include "Conjunto_Cursos.hh"
  
void Conjunto_Cursos::anadir(Curso &c)
{
    conj_c.emplace_back(c);
}
  
void Conjunto_Cursos::usuario_baja_curso(const int& id_curso)
{
    conj_c[id_curso-1].usuario_dar_baja_curso();
}
  
void Conjunto_Cursos::inscribir_usuario_a_curso()
{
    conj_c[iterador].usuario_inscribir_curso();
}
  
void Conjunto_Cursos::curso_inizializar_iterador()
{
    //Inicializa el iterador del Curso que hay en conj_c[iterador]
    conj_c[iterador].inizializar_iterador();
}
  
void Conjunto_Cursos::curso_incrementar_iterador()
{
    //Incrementa en una unidad el iterador del Curso que hay en conj_c[iterador]
    conj_c[iterador].incrementar_iterador();
}
  
void Conjunto_Cursos::apuntar(const int &id_p)
{
    iterador = id_p-1;
}
  
void Conjunto_Cursos::usuario_finaliza_curso()
{
    conj_c[iterador].usuario_finaliza_curso();
}
  
bool Conjunto_Cursos::existe(const int& id)
{
    if (0 < id and id <= conj_c.size()) {
       iterador = id-1;
       return true;
    }
    else return false;
}
  
int Conjunto_Cursos::tamano() const
{
    return conj_c.size();
}
  
bool Conjunto_Cursos::curso_end() const
{
    return conj_c[iterador].end();
}
  
void Conjunto_Cursos::curso_sesion_iterador(string &id_s) const
{
    conj_c[iterador].valor(id_s);
}
  
bool Conjunto_Cursos::curso_contiene_problema(const string &id_p, string &id_s) const
{
    return conj_c[iterador].contiene_problema(id_p, id_s);
}
  
int Conjunto_Cursos::usuarios_actuales_curso() const
{
    return conj_c[iterador].usuarios_actuales();
}
  
void Conjunto_Cursos::inicializar(Conjunto_Sesiones& conj_s)
{
    int n;
    cin >> n;
    conj_c = vector<Curso>(n);
    for (int i = 0; i < n; ++i) {
	Curso c(i+1);
	c.leer(); // Lee el identificador de las Sesiones que forman parte del Curso
	c.inizializar_iterador();
	// Hacemos un recorrido por los identificadores de las sesiones del Curso
	while (not c.end()) {
	    string id_s;
	    c.valor(id_s); // Obtenemos el identificador de la sesion
	    conj_s.apuntar(id_s);
	    conj_s.anadir_problemas_a_curso(c); // Añadimos los problemas que tiene la Sesion al Curso
	    c.incrementar_iterador();
	}
	conj_c[i] = c;
    }
}
  
void Conjunto_Cursos::listar() const
{
    for (int i = 0; i < conj_c.size(); ++i)
	conj_c[i].escribir_curso();
}
  
void Conjunto_Cursos::escribir_curso() const
{
    conj_c[iterador].escribir_curso();
}
