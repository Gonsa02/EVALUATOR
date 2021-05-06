/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_
#include "Conjunto_Sesiones.hh"
#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#include <map>
using namespace std;
#endif

/** @class Usuario
    @brief Representa un Usuario

*/


class Usuario
{
public:

    //Modificadoras

    /** @brief Añade un problema correcto al Usuario.

      \pre En el parámetro "id_problema" se encuentra el identificador de un problema que ha sido resuelto correctamente por el parámetro implícito y que además, forma parte del curso que está cursando actualmente.
      \post Se ha añadido al registro de problemas resueltos del parámetro implícito el identificador del problema resuelto y se ha quitado de la lista de problemas enviables.
      */
    void anadir_problema_correcto(string id_problema);

    /** @brief Quita un Problema enviable al Usuario.

      \pre Existe un problema con id "id_problema" en el registro de problemas enviables del parámetro implícito.
      \post Se ha quitado al registro de problemas enviables del parámetro implícito el identificador del Problema.
      */
    void quitar_problema_enviable(string id_problema);

    /** @brief Añade un Problema intentado al Usuario.

      \pre <em>cierto</em>
      \post Se ha añadido al registro de problemas intentados del parámetro implícito el identificador del Problema.
      */
    void anadir_problema_intentado(string id_problema);

    /** @brief Incrementa el número de envios totales que el Usuario ha hecho.

      \pre <em>cierto</em>
      \post Se ha incrementado en una unidad el número de envios totales que el parámetro implícito ha hecho.
      */
    void incrementar_envios_totales();

    /** @brief Incrementa el número de problemas intentados que el Usuario ha hecho.

      \pre <em>cierto</em>
      \post Se ha incrementado en una unidad el número de problemas intentados que el parámetro implícito ha hecho.
      */
    void incrementar_problemas_intentados();

    /** @brief Inscribe al Usuario en un Curso.

      \pre El Usuario no está inscrito a ningún curso.
      \post El parámetro implícito cuenta con el registro de que está cursando un Curso y también de el id del Curso y además se le han añadido los problemas a los que tiene aceso del curso.
      */
    void inscribir_a_curso(Curso& c, const Conjunto_Sesiones& conj_s);

    /** @brief Prepara al Usuario para cursar otro curso.

      \pre El parametro implícito está cursando un curso actualmente y ya ha terminado todos sus problemas.
      \post El parametro implícito está preparado para cursar otro curso correctamente.
      */
    void finalizar_curso();

    /** @brief Actualiza los Problemas enviables del Usuario a partir de un Problema.
     
      \pre El id_problema se encuentra en la Sesion "s".
      \post Se han añadido los problemas enviables a los que tiene acceso el parámetro implícito gracias a haber resuelto ahora o anteriormente el Problema con id_problema.
    */
    void actualizar_problemas_enviables(string id_problema, const Sesion& s);

    //Consultoras

    /** @brief Consulta el nombre del Usuario

      \pre El parámetro implícito tiene un nombre asignado.
      \post Retorna el nombre del parámetro implícito.
    */
    string obtener_nombre() const; 

    /** @brief Consulta si el parámetro implícito está cursando un curso.
	
	\pre <em>cierto</em>
	\post El resultado indica si el parametro implícito está cursando un curso.
    */
    bool inscrito_a_curso() const;

    /** @brief Consulta el identificador del Curso que está cursando el Usuario.

      \pre El parametro implícito está cursando un Curso.
      \post Retorna el identificador del Curso que está cursando el parametro implícito.
    */
    int curso() const;

    /** @brief Consulta el número de problemas a los que tiene acceso a hacer un envio el Usuario.

      \pre <em>cierto</em>
      \post Retorna el número de problemas enviables que tiene el parámetro implícito.
      */
    int num_problemas_enviables() const;

    /** @brief Consulta si un Usuario puede hacer un envio a un Problema.

      \pre El parámetro implícito está cursando un Curso. En el parámetro "id_problema" se encuentra el identificador del problema el cual queremos consultar si el parámetro implícitopuede hacer un envio o no.
      \post El resultado indica si el parametro implícito cumple los prerequisitos para poder hacer un envio al Problema con identificador = "id_problema".
    */
    bool cumple_requisitos(string id_problema) const;

    /** @brief Consulta si el Usuario ha resuelto un Problema.

      \pre <em>cierto</em>
      \post El resultado indica si el Usuario ha resuelto el Problema con identificador "id_problema".
      */
    bool problema_resuelto(string id_problema) const;

    /** @brief Consulta si el Usuario ha intentado un Problema.

      \pre <em>cierto</em>
      \post El resultado indica si el Usuario ha intentado el Problema con identificador "id_problema".
      */
    bool problema_intentado(string id_problema) const;

    //Escritura

    /** @brief Escribe información del parámetro implícito.

      \pre <em>cierto</em>
      \post Escribe cuantos envios en total ha realizado, cuantos problemas ha resuelto, cuentos ha intentado resolver y el id del curso en el cual está inscrito o cero si no está inscrito en ninguno.
    */
    void escribir_usuario() const;

    /** @brief Escribe los problemas enviables del parámetro implícito.

      \pre <em>cierto</em>
      \post Se han escrito por orden creciente de identificador los problemas que el usuario no ha solucionado todavía en el curso en el que está inscrito actualmente, pero a los cuales ya puede realizar un envío.
      */
    void escribir_problemas_enviables() const;

    /** @brief Escribe los problemas resueltos del parámetro implícito.

      \pre <em>cierto</em>
      \post Se han escrito por orden creciente de identificador los problemas que el parámetro implícito ya ha solucionado con éxito, ya sea en el curso en el que está inscrito actualmente (si lo está) como los resueltos en curssos anteriores. Además también se imprime el número de enviós realizados por el usuario a cada problema del listado.
      */
    void escribir_problemas_resueltos() const;

    /** @brief Operación de lectura

      \pre En el canal standard de entrada se encuentra el nombre del Usuario.
      \post Se ha añadido el nombre al parámetro implícito.
    */
    void leer();

private:
    int envios_totales, problemas_intentados, id_curso_inscrito;
    bool inscrito;
    string nombre;
    map<string,int> pro_resueltos;
    map<string,int> pro_enviables;
};

#endif
