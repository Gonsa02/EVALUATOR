/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
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

    /** @brief Constructora con identificador de la clase Curso.

      \pre <em>cierto</em>
      \post Retorna una instancia de la clase Curso con identificador = "id_c.
      */
    Curso(const int& id_c);

    //Modificadoras

    /** @brief Añade o modifica el id de un Curso.

      \pre <em>cierto</em>
      \post El prarámetro implícito tiene el identficador = "id".
      */
    void anadir_id(const int& id);

    /** @brief Añade el identificador de un Problema y el identificador de una Sesion del Curso al Curso.

      \pre <em>cierto</em>
      \post Se le han añadido los identificadores de los problemas de la Sesion al parámetro implícito.  Además, en caso que haya intersección, queda registrado en el parámetro implícito  que existe esa intersección.
      */
    void anadir_problema_sesion(const string& id_problema, const string& id_sesion);

    /** @brief Incrementa el numero de usuarios que estan cursando el Curso.

	\pre <em>cierto</em>
	\post Se ha incrementado en una unidad el número de estudiantes que están cursando el Curso.
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
      \post "id" = identificador del parámetro implícito.
    */
    void obtener_id(int& id) const;

    /** @brief Consulta el numero de usuarios inscritos actualmente.

      \pre <em>cierto</em>
      \post Retorna el numero de usuarios inscritos actualmente en el Curso.
      */
    int usuarios_actuales() const;

    /** @brief Consulta si existe un Problema en el Curso
	
	\pre <em>cierto</em>
	\post El resultado indica si el parametro implícito contiene el problema, en caso afirmativo "id_s" = identificador de la Sesion en la cual se encuentra el Problema en el parámetro implícito.

    */

    bool contiene_problema(const string& id_p, string& id_s) const;

    /** @brief Consulta si existe intersección entre los problemas de las diferentes sesiones.
     
     \pre <em>cierto</em>
     \post El resultado indica si existe intersección entro los problemas de las diferentes sesiones del parámetro implícito.
     */
    bool existe_interseccion() const;

    /** @brief Consulta la Sesion de un Problema
	
	\pre El Curso contiene un Problema con el "ID" que le pasen al parámetro de la función.
	\post Retorna el identificador de la Sesion en la cual se encuentra el Problema con identificador "ID" en el parámetro implícito.
    */
    void sesion_problema(const string& ID, string& id_s) const;

    /** @brief Consulta el número de sesiones que tiene el Curso

      \pre <em>cierto</em>
      \post Retorna el número de sesiones que tiene el parámetro implícito.
    */
    int tamano() const;

    //Lectura y escritura

    /** @brief Operación de escritura de los identificadores de las sesiones que forman parte del parametro implícito.

      \pre <em>cierto</em>
      \post Escribe los identificadores de todas las Sesiones que forman parte del parametro implícito, en el mismo orden en el que se leyeron cuando se creó el curso.
    */
    void escribir_sesiones() const;

    /** @brief Operación de escritura del parametro implícito

      \pre <em>cierto</em>
      \post Escribe el número de usuarios actuales o pasados que lo han completado, el número de usuarios inscritos actualmente, el número de sesiones que lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el Curso.

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

    // Iterador

    /** @brief Inizializa el iterador de sesiones al inicio en la primera Sesion del Curso.
    
      \pre <em>cierto</em>
      \post El iterador del parámetro implícito apunta a la primera Sesion del parámetro implícito.
    */
    void inizializar_iterador();

    /** @brief Icrementa el iterador para que apunte a la siguiente Sesion del parámetro implícito.
    
      \pre El iterador no apunta al elemento end().
      \post El iterador del parámetro implícito apunta a la siguiente Sesion del parámetro implícito.
    */
    void incrementar_iterador();

    /** @brief Consulta si el iterador ya ha llegado al final.

      \pre <em>cierto</em>
      \post Retorna si el iterador apunta al último elemento del parámetro implícito o no.
    */
    bool end() const;

    /** @brief Consulta el valor al qual apunta el iterador del Curso.

      \pre El iterador apunta a una Sesion del parámetro implícito.
      \post "id_s" és el identificador de la Sesion al cual apunta el iterador del parámetro implícito.
    */
    void valor(string& id_s) const;

private:
    int id, usuarios_curso_completado, usuarios_cursando_curso;
    bool interseccion;
    vector<string> id_conj_s;
    map<string,string> problema_sesion;
    int iterador;
};

#endif
