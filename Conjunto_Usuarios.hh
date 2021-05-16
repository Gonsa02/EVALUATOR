/** @file Conjunto_Usuarios.hh
    @brief Especificación de la clase Conjunto_Usuarios
*/

#ifndef _CONJUNTO_USUARIOS_HH_
#define _CONJUNTO_USUARIOS_HH_

#include "Usuario.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Conjunto_Usuarios
    @brief Representa un Conjunto de Usuarios.
*/

class Conjunto_Usuarios
{
public:

    //Modificadoras
    
    /** @brief Añade un Usuario al Conjunto_Usuarios.

    \pre No existe ningún usuario con nombre = "nombre" en el parámetro implícito.
    \post Se ha añadido un Usuario con nombre = "nombre" en el parámetro implícito. 
    */
    void anadir(const string& nombre);

    /** @brief Borra un Usuario del Conjunto_Usuarios.

      \pre El iterador apunta a un Usuario del parámetro implícito que está cursando un Curso.
      \post El Usuario apuntado por el iterador del parámetro implícito ha sido eliminado del registro del parametro implícito.
      */
    void borrar();

    /** @brief Inscribe un Usuario a un Curso.

      \pre El iterador apunta a un Usuario del parámetro implícito que actualmente no está cursando ningún Curso.
      \post El Usuario apuntado por el iterador cuenta con el registro de que está cursando un Curso y también del id del Curso.
    */
    void inscribir_usuario_a_curso(const int& id_c);

    /** @brief Añade un problema enviable a un Usuario.

      \pre El iterador del parámetro implícito apunta a un Usuario.
      \post Se ha añadido el problema enviable al Usuario apuntado por el iterador del parámetro implícito.
      */
    void anadir_problema_enviable(const string& id_p);

    /** @brief Apunta el iterador a un Usuario.
     
      \pre Existe un Usuario con nombre = "nombre" en el parámetro implícito.
      \post El iterador del parámetro implícito apunta al Usuario con nombre = "nombre".
      */
    void apuntar(const string& nombre);

    /** @brief Añade un intento de un Problema a un Usuario.

      \pre El iterador del parámetro implícito apunta a un Usuario.
      \post Se ha incrementado en una unidad los intentos al problema con identificador = "id_p" i también los envios totales del Usuario al cual apunta el parámetro implícito. En caso de que sea el primer intento, se ha incrementado en una unidad el número de problemas intentados.
    */
    void usuario_envio_problema(const string& id_p);

    /** @brief Prepara a un Usuario para cursar otro Curso.

      \pre El iterador del parámetro implícito apunta a un Usuario.
      \post El Usuario apuntado por el iterador no está inscrito en ningún Curso.
      */
    void usuario_finaliza_curso();

    //Consultoras
    
    /** @brief Consulta si existe un Usuario.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene un Usuario "u" con el nombre = "nombre", si lo contiene el iterador del parámetro implícito apunta a ese Usuario.
      */
    bool existe(const string& nombre);

    /** @brief Consulta el número de usuarios que pertenecen al parámetro implícito.
     
      \pre <em>cierto</em>
      \post El resultado retorna el número de usuarios que pertenecen al parámetro implícito actualmente.
      */
    int numero_usuarios() const;

    /** @brief Consulta si el Usuario está inscrito a un Curso

      \pre El iterador apunta a un Usuario del parámetro implícito.
      \post El resultado indica si el Usuario apuntado por el iterador del parámetro implícito está inscrito a un Curso, en caso afirmativo en id_c se encuentra el identificador del curso que está cursando i en caso contrario id_c no se modifica.
      */
    bool usuario_inscrito_a_curso(int& id_c) const;

    /** @brief Consulta el identificador del Curso cursando actualmente un Usuario.

      \pre El iterador apunta a un Usuario que está cursando un Curso del parámetro implícito.
      \post "id" = identificador del Curso que está cursando el usuario apuntado por el iterador del parámetro implícito.
      */
    void curso_usuario(int& id) const;

    /** @brief Consulta si un Usuario ha resuelto anteriormente un Problema.

      \pre El iterador del parámetro implícito apunta a un Usuario.
      \post El resultado indica si el Usuario apuntado por el iterador ya había resuelto anteriormente el problema con identificador = id_p.
      */
    bool usuario_problema_resuelto(const string& id_p) const;

    /** @brief Añade un Problema correcto a un Usuario

      \pre El iterador del parámetro implícito apunta a un Usuario i el Problema con id_problema es un problema enviable del Usuario.
      \post Se ha añadido al registro de problemas resueltos del Usuario apuntado por el iterador del parámetro implícito y se ha quitado de los problemas enviables del Usuario.
      */
    void usuario_problema_correcto(const string& id_p);

    /** @brief Consulta el número de problemas enviables de un Usuario.

      \pre El iterador apunta a un Usuario del parámetro implícito.
      \post Retorna el número de problemas enviables que tiene el Usuario apuntado por el iterador del parámetro implícito.
      */
    int num_problemas_enviables_usuario() const;

    // Lectura y Escritura

    /** @brief Lectura inicial de usuarios.
    
      \pre En el canal standard de entrada estan preparados los diferentes usuarios que se desea añadir inicialmente al conjunto de usuarios. Primero entra el número N de usuarios que se desea introducir.
      \post Se han añadido los usuarios al conjunto de usuarios.
      */
    void inicializar();

    /** @brief Lista todos los usuarios del Conjunto_Usuarios.

      \pre <em>cierto</em>
      \post Para cada Usuario en el parametro implícito, escribe cuantos envios en total ha realizado, cuantos problemas ha resuelto, cuentos ha intentado resolver y el id del curso en el cual está inscrito o cero si no está inscrito en ninguno.
    */
    void listar() const;

    /** @brief Escribe los problemas enviables de un Usuario.

      \pre El iterador del parámetro implícito apunta a un Usuario y ese Usuario está cursando un Curso.
      \post Se han escrito en orden creciente de identificador los problemas que el Usuario apuntado por el iterador del parámetro implícito que todavía no ha solucionado del Curso en el que está inscrito actualmente, però a los cuales ya puede relizar un envío.
      */
    void usuario_escribir_problemas_enviables() const;

    /** @brief Escribe los problemas resueltos de un Usuario.

      \pre El iterador del parámetro implícito apunta a un Usuario.
      \post Se han escrito en orden creciente de identificador los problemas que el Usuario apuntado por el iterador del parámetro implícito que ya ha solucionado con éxito, ya sea en el Curso en el que está inscrito actualmente (si lo está) como los resueltos en cursos anteriores. Además también se imprime el número de envios realizados por el Usuario a cdaa problema del listado.
      */
    void usuario_escribir_problemas_resueltos() const;

    /** @brief Escribe la información de un Usuario

      \pre El iterador del parámetro implícito apunta a un Usuario.
      \post Escribre cuantos envios en total ha realizado el Usuario apuntado por el iterador del parámetro implícito, cuantos problemas ha resuelto, cuantos problemas ha intentado resolver y el id del Curso en el cual está inscrito o coero si no está inscrito en ninguno.
      */
    void escribir_usuario() const;

private:
    /** @brief Guarda el conjunto de Usuarios con un diccionario que tiene como clave el nombre de un Usuario y como valor la instáncia de la clase Usuario con el mismo nombre que la clave del diccionario.*/
    map<string,Usuario> conj_u;

    /** @brief Iterador interno de la classe Conjunto_Usuarios.*/
    map<string,Usuario>::iterator iterador;
};
#endif
