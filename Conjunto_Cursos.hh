/** @file Conjunto_Cursos.hh
    @brief Especificación de la clase Conjunto_Cursos
*/

#ifndef _CONJUNTO_CURSOS_HH_
#define _CONJUNTO_CURSOS_HH_

#include "Conjunto_Sesiones.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Conjunto_Cursos
    @brief Representa un Conjunto de Cursos.
*/

class Conjunto_Cursos
{
public:

    //Modificadoras
    
    /** @brief Añade una Curso al Conjunto_Cursos.

    \pre El Curso cumple con la restricción de no repetición de problemas del mismo Curso.
    \post Se ha añadido el Curso "c" al parámetro implícito. 
    */
    void anadir(const int& id, Curso& c);

    /** @brief Actualiza un Curso del Conjunto_Cursos

    \pre El Curso "c" existe en el parámetro implícito.
    \post Se ha sustituido el Curso del parámetro implícito con el mismo identificador que "c" por "c".
    */
    void actualizar(const Curso& c);

    /** @brief Da de baja de un Curso.

      \pre Existe un Curso con identificador = "id_curso" en el parámetro implícito.
      \post Se ha decrementado el número de usuarios inscritos al Curso con identificador = "id_curso" del parámetro implícito.
      */
    void usuario_baja_curso(const int& id_curso);

    /** @brief Incrementa el número de Usuarios en una unidad de un Curso.
    \pre El iterador del parámetro implícito apunta a un Curso del parámetro implícito.
    \post Se ha incrementaddo en una unidad el número de estudiantes que están cursando el Curso.
    */
    void inscribir_usuario_a_curso();

    /** @brief Iniciliza el iterador de un Curso.

     \pre El iterador del parámetro implícito apunta a un Curso del parámetro implícito.
     \post El iterador del Curso apuntado por el iterador del parámetro implícito apunta a la primera Sesión del Curso.
    */
    void curso_inizializar_iterador();

    /** @brief Incrementa el iterador de un Curso.

     \pre El iterador del parámetro implícito apunta a un Curso del parámetro implícito, dónde el apuntador del Curso no está apuntando a su final.
     \post El iterador del Curso apuntado por el iterador del parámetro implícito apunta a la siguiente Sesión del Curso.
    */
    void curso_incrementar_iterador();

    /** @brief Apunta el iterador a un Curso
     
      \pre Existe un Curso con identificador = "id_c" en el parámetro implícito.
      \post El iterador del parámetro implícito apunta al Curso con identificador = "id_c".
      */
    void apuntar(const int& id_p);

    /** @brief Incrementa el número de usuarios que han completado un Curso.

      \pre El iterador del parámetro implícito apunta a un Curso.
      \post Se ha incrementado en una unidad el número de usuarios que han completado el Curso apuntado por el parámetro implícito y se ha decrementado en una undiad el número de usuarios que están cursando el Curso actualmente.
      */
    void usuario_finaliza_curso();

    //Consultoras
    
    /** @brief Consulta si existe un Curso.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene un Curso con identificador identificador = "id" y además, en caso que exista el iterador del parámetro implícito apunta a ese Curso.
      */
    bool existe(const int& id);
    
    /** @brief Obtiene el curso mediante identificador.

    \pre Existe un Curso con identificador "id".
    \post En el Curso "c" se encuentra el Curso con identificador "id" del parámetro implícito.
    */
    void obtener_con_id(const int& id, Curso& c);

    /** @brief Consulta el número de cursos que tiene el Conjunto_Cursos

      \pre <em>cierto</em>
      \post Retorna el número de cursos que tiene el parámetro implícito.
    */
    int tamano() const;

    /** @brief Consulta si el iterador de un Curso apunta a su final.
     \pre El iterador del parámetro implícito apunta a un Curso del parámetro implícito.
     \post El resultado indica si el iterador del Curso apunta a su final.
     */
    bool curso_end() const;

    /** @brief Consulta la Sesión a la qual apunta el iterador de un Curso.

      \pre El iterador del parámetro implícito apunta a un Curso que apunta a una Sesión.
      \post "id_s" = identificador de la Sesión apuntada por el iterador del Curso apuntado por el iterador del parámetro implícito.
      */
    void curso_sesion_iterador(string& id_s) const;

    /** @brief Consulta si un Curso contiene un Problema.
     
      \pre El iterador del parámetro implícito apunta a un Curso.
      \post El resultado indica si el Curso apuntado por el iterador del parámetro implícito contiene un Problema con identificador = "id_p", en caso afirmativo en "id_s" está el identificador de la Sesión en la cual se encuentra ese Problema en el Curso, en caso contrario id_s no se modifica.
      */
    bool curso_contiene_problema(const string& id_p, string& id_s) const;

    /** @brief Consulta los usuarios actuales de un Curso.
     
      \pre El iterador del parámetro implícito apunta a un Curso.
      \post El resulado retorna el número de usuarios que actualmente están cursando el Curso apuntado por el iterador del parámetro implícito.
      */
    int usuarios_actuales_curso() const;

    //Lectura y escritura

    /** @brief Lectura inicial de cursos.
    
      \pre En el canal standard de entrada estan preparados los diferentes cursos que se desea añadir inicialmente al conjunto de cursos. Primero se lee el numero N que indica cuantos cursos van a entrar.
      \post Se han añadido los cursos al conjunto de cursos.
      */
    void inicializar(Conjunto_Sesiones& conj_s);

    /** @brief Lista todos los cursos del Conjunto_Cursos.
     
      \pre <em>cierto</em>
      \post Para cada Curso que haya en el parametro implícito, se escribe el numero de usuarios actualos o pasados que lo han completado, el numero de usuarios inscritos actualmente, el numero de sesiones qeu lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el Curso.
      */
    void listar() const;    

    /** @brief Escribe un Curso.

      \pre El iterador del parámetro implícito apunta a un Curso.
      \post Escribe el número de usuarios actuales o pasados que han completado el Curso apuntado por el iterador del parámetro implícito, el número de usuarios inscritos actualmente, el número de sesiones que lo forman y los identificadores de dichas sesiones, en el mimso orden en el que se leyeron cuando se creó el Curso.
      */
    void escribir_curso() const;

private:
    map<int,Curso> conj_c;
    map<int,Curso>::iterator iterador;
};
#endif
