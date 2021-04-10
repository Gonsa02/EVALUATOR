/** @file Conjunto_Cursos.hh
    @brief Especificación de la clase Conjunto_Cursos
*/

#ifndef _CONJUNTO_CURSOS_HH_
#define _CONJUNTO_CURSOS_HH_

#include "Curso.hh"

#ifndef NO_DIAGRAM
#endif

/** @class Conjunto_Cursos
    @brief Representa un Conjunto de Cursos.
*/

class Conjunto_Cursos
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto de la clase Conjunto_Cursos.
     
	Se ejecuta automáticamente al declarar un conjunto de cursos.
	\pre <em>cierto</em>
	\post El resultado es un conjunto de cursos.
    */

    Conjunto_Cursos();

    //Destructora

    /** @brief Destructora de la clase Conjunto_Cursos.

      \pre <em>cierto</em>
      \post Se destruye el parametro implícito
    */
    ~Conjunto_Cursos();

    //Modificadoras
    
    /** @brief Añade una Curso al Conjunto_Cursos.

    \pre El Curso cumple con la restricción de no repetición de problemas del mismo Curso.
    \post Se ha añadido el Curso "c" al parámetro implícito. 
    */
    void añadir(const Curso& c);

    //Consultoras
    
    /** @brief Consulta si existe un Curso con el mismo identificador.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene un Curso "c" con el mismo identificador y además, en caso que exista c = Curso del parámetro implícito con el identificador de c, en caso contrario "c" no se ve modificado.
      */
    bool existe(Curso& c);
    
    /** @brief Consulta si existe un Curso con las mismas sesiones.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene un Curso "c" con las mismas sesiones.
      */
    bool existe_con_mismas_sesiones(const Curso& c) const;

    /** @brief Obtiene el curso mediante identificador.

    \pre Existe un Curso con identificador "id".
    \post En el Curso "c" se encuentra el Curso con identificador "id" del parámetro implícito.
    */
    void obtener_con_id(int id, Curso& c);

    //Lectura y escritura

    /** @brief Lectura inicial de cursos.
    
      \pre En el canal standard de entrada estan preparados los diferentes cursos que se desea añadir inicialmente al conjunto de cursos.
      \post Se han añadido los cursos al conjunto de cursos.
      */
    void inicializar();

    /** @brief Lista todos los cursos del Conjunto_Cursos.
     
      \pre <em>cierto</em>
      \post Para cada Curso que haya en el parametro implícito, se escribe el numero de usuarios actualos o pasados que lo han completado, el numero de usuarios inscritos actualmente, el numero de sesiones qeu lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el Curso.
      */
    void listar() const;    
};
#endif
