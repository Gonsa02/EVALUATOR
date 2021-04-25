/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
using namespace std;
#endif

/** @class Usuario
    @brief Representa un Usuario

*/


class Usuario
{
public:
    //Constructoras

    /** @brief Creadora por defecto de la clase Usuario.
     
	Se ejecuta automáticamente al declarar un Usuario.
	\pre <em>cierto</em>
	\post El resultado es un Usuario.
    */
    Usuario();

    //Destructora

    /** @brief Destructora de la clase Usuario.

      \pre <em>cierto</em>
      \post Se destruye el parametro implícito
    */
    ~Usuario();

    //Modificadoras

    /** @brief Incrementa el número de problemas que el Usuario ha intentado resolver.

      \pre <em>cierto</em>
      \post Se ha incrementado en una unidad el número de problemas que el parámetro implícito ha intentado resolver.
      */
    void incrementar_intentos_problemas();

    /** @brief Añade un problema correcto al Usuario.

      \pre En el parámetro "id_problema" se encuentra el identificador de un problema que ha sido resuelto correctamente por el parámetro implícito y que además, forma parte del curso que está cursando actualmente.
      \post Se ha añadido al registro de problemas resueltos del parámetro implícito el identificador del problema resuelto y se ha quitado de la lista de problemas enviables.
      */
    void añadir_problema_correcto(string id_problema);

    /** @brief Añade un Problema enviable al Usuario.

      \pre En el parámetro "id_problema" se encuentra el identificador de un problema que el parametro implicito ya tiene disponible para enviar por el parámetro implícito.
      \post Se ha añadido al registro de problemas enviables del parámetro implícito el identificador del Problema.
      */
    void añadir_problema_enviable(string id_problema);

    /** @brief Quita un Problema enviable al Usuario.

      \pre Existe un problema con id "id_problema" en el registro de problemas enviables del parámetro implícito.
      \post Se ha quitado al registro de problemas enviables del parámetro implícito el identificador del Problema.
      */
    void quitar_problema_enviable(string id_problema);

    /** @brief Añade un Problema intentado al Usuario.

      \pre <em>cierto</em>
      \post Se ha añadido al registro de problemas intentados del parámetro implícito el identificador del Problema.
      */
    void añadir_problema_intentado(string id_problema);

    /** @brief Incrementa el número de envios totales que el Usuario ha hecho.

      \pre <em>cierto</em>
      \post Se ha incrementado en una unidad el número de envios totales que el parámetro implícito ha hecho.
      */
    void incrementar_envios_totales();

    /** @brief Inscribe al Usuario en un Curso.

      \pre El Usuario no está inscrito a ningún curso y en el parámetro "id_curso" se encuentre el número identificador del curso al cual lo vamos a inscribir.
      \post El parámetro implícito cuenta con el registro de que está cursando un Curso y también de el id del Curso.
      */
    void inscribir_a_curso(int id_curso);

    /** @brief Prepara al Usuario para cursar otro curso.

      \pre El parametro implícito está cursando un curso actualmente y ya ha terminado todos sus problemas.
      \post El parametro implícito está preparado para cursar otro curso correctamente.
      */
    void finalizar_curso();

    //Consultoras

    /** @brief Consulta el nombre del Usuario

      \pre El parámetro implícito tiene un nombre asignado.
      \post Retorna el nombre del parámetro implícito.
    */
    string obtener_nombre() const; 

    /** @brief Consulta el número de problemas que el Usuario ha intentado resolver.

      \pre <em>cierto</em>
      \post Retorna el número de problemas que el parámetro implícito ha intentado resolver.
    */
    int num_intentos_problemas() const;

    /** @brief Consulta el número cuantos problemas ha resuelto correctamente el Usuario.

      \pre <em>cierto</em>
      \post Retorna el número de problemas que el parámetro implícito ha resuelto correctamente.
    */
    int num_problemas_correctos() const;

    /** @brief Consulta el número de envios totales que el Usuario ha hecho.

      \pre <em>cierto</em>
      \post Retorna el número de envios totales que el parámetro implícito ha hecho.
    */
    int num_envios_totales() const;

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

    /** @brief Consulta si el Usuario ha intentado solucionar un Problema.

      \pre <em>cierto</em>
      \post El resultado indica si el Usuario ha intentado solucionar el Problema con identificador "id_problema".
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
    int intentos_problemas, envios_totales, id_curso_inscrito;
    bool inscrito;
    string nombre;
    set<string> pro_resueltos;
    set<string> pro_resueltos_curso_actual;
    set<string> pro_intentados;
    set<string> pro_enviables;

};

#endif
