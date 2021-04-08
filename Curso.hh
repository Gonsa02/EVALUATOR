/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "Sesion.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

/** @class Curso
    @brief Representa un Curso.

    Cada curso esta formado por un conjunto de sesiones donde la intersección entre cualquier par de sesiones del curso es nula y también consta de un valor entero entre 1 y N que lo identifica.
*/


// Comentario para mi: la gestion de los usuarios del curso, és decir, algunos de las modificadoras que tengo aquí, deberian ser responsabilidad de la clase Plataforma.

class Curso
{
public:
    //Constructoras

    /** @brief Creadora por defecto de la clase Curso.
     
	Se ejecuta automáticamente al declarar un Curso.
	\pre <em>cierto</em>
	\post El resultado es un Curso sin usuarios ni sesiones.
    */
    Curso();

    /** @brief Creadora de un Curso con sesiones.
     
	\pre En el parámetro "id_sesiones" se encuentra un vector con todas las sesiones que debe contener el Curso.
	\post El resultado es un Curso con todos las sesiones que contenia el vector "id_sesiones" y sin usuarios que lo esten cursando.
    */
    Curso(vector<string> id_sesiones);

    //Destructora

    /** @brief Destructora.

      \pre <em>cierto</em>
      \post Se destruye el parametro implícito
    */
    ~Curso();


    //Modificadoras

    /** @brief Incrementa el numero de usuarios que estan cursando el Curso.

	\pre <em>cierto</em>
	\post Se ha incrementado en una unidad el numero de estudiantes que estan cursando el Curso.
    */
    void usuario_inscribir_curso();

    /** @brief Incrementa el numero de usuarios que han completado el Curso.

	\pre <em>cierto</em>
	\post Se ha incrementado en una unidad el numero de estudiantes que han completado el Curso y se ha decrementado en una unidad el número de usuarios que estan cursando el Curso actualmente.
    */
    void usuario_finaliza_curso();


    //Consultoras

    /** @brief Consulta el numero de usuarios actuales o pasados que han completado el Curso.

      \pre <em>cierto</em>
      \post Retorna el numero de usuarios actuales o pasados que han completado el Curso.
    */
    int usuarios_curso_complteado() const;
    
    /** @brief Consulta el numero de usuarios inscritos actualmente.

      \pre <em>cierto</em>
      \post Retorna el numero de usuarios inscritos actualmente en el Curso.
      */
    int usuarios_actuales() const;

    /** @brief Consulta el numero de sesiones que tiene el parametro implícito.

      \pre <em>cierto</em>
      \post Retorna el numero de sesiones que tiene el parametro implícito.
      */
    int numero_sesiones() const;

    /** @brief Consulta si existe un problema en el curso
	
	\pre En "ID" se encuentra el identificador del problema que queremos consultar si esta o no en el curso.
	\post El resultado indica si el parametro implícito contiene el problema.

    */

    bool contiene_problema(string ID) const;

    /** @brief Consulta la sesion de un problema
	
	\pre El curso contiene un problema con el "ID" que le pasen al parámetro de la función.
	\post La función retorna el identificador de la sesion en la cual se encuentra el problema con identificador "ID" en este curso.
    */
    string sesion_problema(string ID) const;


    //Lectura y escritura

    /** @brief Operación de escritura de los identificadores de las sesiones que forman parte del parametro implícito.

      \pre <em>cierto</em>
      \post Escribe los identificadores de todas las Sesiones que forman parte del parametro implícito, en el mismo orden en el que se leyeron cuando se creó el curso.
    */
    void escribir_sesiones() const;

    /** @brief Operación de escritura del parametro implícito

      \pre <em>cierto</em>
      \post Escribe el numero de usuarios actualos o pasados que lo han completado, el numero de usuarios inscritos actualmente, el numero de sesiones qeu lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el curso.

    */
    void escribir_curso() const;
};

#endif
