/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Usuario
    @brief Representa un Usuario

*/


class Usuario
{
public:

    //Constructora

    /** @brief Crea un Usuario con nombre.

      \pre <em>cierto</em>
      \post El resultado es un Usuario con nombre = "nombre"
      */
    Usuario(const string& nombre);

    //Modificadoras

    /** @brief Añade un problema correcto al Usuario.

      \pre En el parámetro "id_problema" se encuentra el identificador de un problema que ha sido resuelto correctamente por el parámetro implícito y que además, forma parte del curso que está cursando actualmente.
      \post Se ha añadido al registro de problemas resueltos del parámetro implícito el identificador del problema resuelto y se ha quitado de los problemas enviables.
      */
    void anadir_problema_correcto(const string& id_problema);

    /** @brief Añade el identificador de un Problema nuevo al Usuario.
     
      \pre <em>cierto</em>
      \post Se ha añadido el identificador del Problema al registro de problemas enviables del parámetro implícito.
      */
    void anadir_problema_enviable(const string& id_problema);

    /** @brief Añade un intento a un Problema enviable.

      \pre El parámetro implícito tiene acceso a hacer un intento a ese problema.
      \post Se ha incrementado en una unidad los intentos al problema con id = "id_problema" i también los envios totales. En caso de que sea el primer intento, se ha incrementado en una unidad el número de problemas intentados.
      */
    void anadir_intento_problema(const string& id_problema);

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
      \post El parámetro implícito cuenta con el registro de que está cursando un Curso y también de el id del Curso.
      */
    void inscribir_a_curso(const int& id_curso);

    /** @brief Prepara al Usuario para cursar otro Curso.

      \pre <em>cierto</em>
      \post El parametro implícito no está incrito a ningún Curso.
      */
    void finalizar_curso();

    //Consultoras

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

    /** @brief Consulta si el Usuario ha resuelto un Problema.

      \pre <em>cierto</em>
      \post El resultado indica si el Usuario ha resuelto el Problema con identificador "id_problema".
      */
    bool problema_resuelto(const string& id_problema) const;

    //Escritura

    /** @brief Escribe información del parámetro implícito.

      \pre <em>cierto</em>
      \post Escribe cuantos envios en total ha realizado, cuantos problemas ha resuelto, cuantos problemas ha intentado resolver y el id del Curso en el cual está inscrito o cero si no está inscrito en ninguno.
    */
    void escribir_usuario() const;

    /** @brief Escribe los problemas enviables del parámetro implícito.

      \pre <em>cierto</em>
      \post Se han escrito por orden creciente de identificador los problemas que el Usuario no ha solucionado todavía en el Curso en el que está inscrito actualmente, pero a los cuales ya puede realizar un envío.
      */
    void escribir_problemas_enviables() const;

    /** @brief Escribe los problemas resueltos del parámetro implícito.

      \pre <em>cierto</em>
      \post Se han escrito por orden creciente de identificador los problemas que el parámetro implícito ya ha solucionado con éxito, ya sea en el Curso en el que está inscrito actualmente (si lo está) como los resueltos en cursos anteriores. Además también se imprime el número de envios realizados por el usuario a cada problema del listado.
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
