/** @file Conjunto_Cursos.hh
    @brief Especificación de la clase Conjunto_Cursos
*/

#ifndef _CONJUNTO_CURSOS_HH_
#define _CONJUNTO_CURSOS_HH_

#include "Conjunto_Sesiones.hh"
#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
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
    void anadir(Curso& c);

    /** @brief Actualiza un Curso del Conjunto_Cursos

    \pre El Curso "c" existe en el parámetro implícito.
    \post Se ha sustituido el Curso del parámetro implícito con el mismo identificador que "c" por "c".
    */
    void actualizar(const Curso& c);

    //Consultoras
    
    /** @brief Consulta si existe un Curso con el mismo identificador.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene un Curso "c" con el mismo identificador y además, en caso que exista c = Curso del parámetro implícito con el identificador de c, en caso contrario "c" no se ve modificado.
      */
    bool existe(Curso& c);
    
    /** @brief Obtiene el curso mediante identificador.

    \pre Existe un Curso con identificador "id".
    \post En el Curso "c" se encuentra el Curso con identificador "id" del parámetro implícito.
    */
    void obtener_con_id(int id, Curso& c);

    /** @brief Consulta el número de cursos que tiene el Conjunto_Cursos

      \pre <em>cierto</em>
      \post Retorna el número de cursos que tiene el parámetro implícito.
    */
    int tamano() const;

    //Lectura y escritura

    /** @brief Lectura inicial de cursos.
    
      \pre En el canal standard de entrada estan preparados los diferentes cursos que se desea añadir inicialmente al conjunto de cursos. Primero se lee el numero N que indica cuantos cursos van a entrar.
      \post Se han añadido los cursos al conjunto de cursos.
      */
    void inicializar();

    /** @brief Lista todos los cursos del Conjunto_Cursos.
     
      \pre <em>cierto</em>
      \post Para cada Curso que haya en el parametro implícito, se escribe el numero de usuarios actualos o pasados que lo han completado, el numero de usuarios inscritos actualmente, el numero de sesiones qeu lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el Curso.
      */
    void listar();    

private:
    map<int, Curso> conj_c;
};
#endif
