/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "Sesion.hh"
#include "Conjunto_Sesiones.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
using namespace std;
#endif

/** @class Curso
    @brief Representa un Curso.

*/


class Curso
{
public:

    //Constructoras

    /** @brief Constructora de la clase Curso.

      \pre <em>cierto</em>
      \post Retorna una instancia de la clase Curso.
      */
    Curso();

    //Modificadoras

    /** @brief Añade o modifica el id de un Curso.

      \pre <em>cierto</em>
      \post El prarámetro implícidto tiene el identficador = "id".
      */
    void añadir_id(int id);

    /** @brief Incrementa el numero de usuarios que estan cursando el Curso.

	\pre <em>cierto</em>
	\post Se ha incrementado en una unidad el numero de estudiantes que estan cursando el Curso.
    */
    void usuario_inscribir_curso();

    /** @brief Incrementa el decrementa el numero de usuarios que estan cursando el Curso.

	\pre <em>cierto</em>
	\post Se ha decrementado en una unidad el numero de estudiantes que estan cursando el Curso.
    */
    void usuario_dar_baja_curso();

    /** @brief Incrementa el numero de usuarios que han completado el Curso.

	\pre <em>cierto</em>
	\post Se ha incrementado en una unidad el numero de estudiantes que han completado el Curso y se ha decrementado en una unidad el número de usuarios que estan cursando el Curso actualmente.
    */
    void usuario_finaliza_curso();

    //Consultoras

    /** @brief Consulta el identificador de un Curso.

      \pre El parámetro implícito tiene asignado un identificador.
      \post Retorna el identificador del parámetro implícito.
    */
    int obtener_id() const;

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

    bool contiene_problema(string ID, Conjunto_Sesiones& conjunto_sesiones) const;

    /** @brief Consulta si existe intersección entre los problemas de las diferentes sesiones.
     
     \pre <em>cierto</em>
     \post El resultado indica si existe intersección entro los problemas de las diferentes sesiones del parámetro implícito.
     */
    bool existe_interseccion(Conjunto_Sesiones& conjunto_sesiones) const;

    /** @brief Consulta la sesion de un problema
	
	\pre El curso contiene un problema con el "ID" que le pasen al parámetro de la función.
	\post La función retorna el identificador de la sesion en la cual se encuentra el problema con identificador "ID" en este curso.
    */
    string sesion_problema(string ID, Conjunto_Sesiones& conjunto_sesiones) const;

    /** @brief Consulta el Problema inicial de cada Sesion que forma el Curso.

      \pre <em>cierto</em>
      \post Devuelve un vector con el identificador del Problema inicial de cada Sesion que forma parte del parámetro implícito.
    */
    vector<string> problemas_iniciales(Conjunto_Sesiones& conjunto_sesiones) const;

    //Lectura y escritura

    /** @brief Operación de escritura de los identificadores de las sesiones que forman parte del parametro implícito.

      \pre <em>cierto</em>
      \post Escribe los identificadores de todas las Sesiones que forman parte del parametro implícito, en el mismo orden en el que se leyeron cuando se creó el curso.
    */
    void escribir_sesiones() const;

    /** @brief Operación de escritura del parametro implícito

      \pre <em>cierto</em>
      \post Escribe el numero de usuarios actuales o pasados que lo han completado, el numero de usuarios inscritos actualmente, el numero de sesiones qeu lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el curso.

    */
    void escribir_curso() const;

    /** @brief Operación de lectura

      \pre En el canal standard de entrada se encuentra el numero de sesiones de las cuales va a constar el Curso (N) y posteriormente van a entrar N sesiones del curso.
      \post Se han añadido las sesiones al parámetro implícito.
    */
    void leer();

    /** @brief Operación de lectura del identificador

      \pre En el canal standard de entrada se encuentra el identificador del parámetro implícito.
      \post Se ha añadido el identificador al parámetro implícito.
    */
    void leer_id();

private:
    int id, usuarios_curso_completado, usuarios_cursando_curso;
    set<string> conj_s;
    vector<string> id_conj_s;
};

#endif
