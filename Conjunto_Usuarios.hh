/** @file Conjunto_Usuarios.hh
    @brief Especificación de la clase Conjunto_Usuarios
*/

#ifndef _CONJUNTO_USUARIOS_HH_
#define _CONJUNTO_USUARIOS_HH_

#include "Usuario.hh"
#include "Conjunto_Sesiones.hh"
#include "Curso.hh"

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

    \pre El Usuario "u" no existe en el parámetro implícito.
    \post Se ha añadido el Usuario "u" al parámetro implícito. 
    */
    void anadir(const Usuario& u);

    /** @brief Borra un Usuario del Conjunto_Usuarios.

      \pre Existe el Usuario "u" en el parámetro implícito.
      \post El Usuario ha sido eliminado del registro del parametro implícito, tambíen se ha borrado de los registros del Curso que actualmente estaba cursando en caso que estubiera cursando uno.
      */
    void borrar(const Usuario& u);

    /** @brief Actualiza un Usuario del Conjunto_Usuarios

    \pre El Usuario "u" existe en el parámetro implícito.
    \post Se ha sustituido el Usuario del parámetro implícito con el mismo nombre que "u" por "u".
    */
    void actualizar(const Usuario& u);

    /* Inscribe un Usuario a un Curso.

    \pre El Usuario "u" no está cursando ningún Curso.
    \post El parámetro implícito cuenta con el registro de que "u" está cursando un Curso y también de el id del Curso y además se le han añadido los problemas a los que tiene aceso del curso.
    */
    void inscribir_usuario_a_curso(const Usuario& u, Curso& c, const Conjunto_Sesiones& conj_s);

    /* @brief Actualiza las estadísticas de un Usuario por el envio que ha hecho.

       \pre Existe un Usuario con nombre = "nombre" en el parámetro implícito y ese Usuario tiene acceso a hacer un envio al Problema con identificador = "id_problema".
       \post Se han incrementado los envios totales i los intentos a ese problema, además en caso de que es la primera vez que se intenta ese Problema, también se ha incrementado el número de problemas intentados.
       */
    void envio_usuario(string nombre, string id_problema);

    /* @brief Actualiza las estadísticas de un Usuario por el envio que ha hecho.

       \pre Existe un Usuario con nombre = "nombre" en el parámetro implícito y ese Usuario tiene acceso a hacer un envio al Problema con identificador = "id_problema".
       \post En el Usuario con nombre = "nombre" consta de que ha resuelto el problema i se le ha quitado de los problemas enviables que tenia. Además se han actualizado los problemas enviables a los que tiene acceso el Usuario y se ha consultado si con este envio correcto el Usuario ha terminado el Curso, en caso afirmativo el Usuario deja de estar inscrito en el Curso i la función retorna "true", si no lo termina retorna "false".
       */
    bool envio_correcto_usuario(string nombre, string id_problema, const Sesion& s);

    //Consultoras
    
    /** @brief Consulta si existe un Usuario

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene el Usuario "u", si lo contiene "u" = al Usuario del parámetro implícito sinó "u" no se ve modificado.
      */
    bool existe(Usuario& u);

    /** @brief Obtiene un Usuario del Conjunto_Usuarios

	\pre Existe un Usuario con nombre = "nombre" en el parámetro implícito.
	\post En "u" se encuentra el Usuario con nombre = "nombre" del parámetro implícito.	
    */
    void obtener(const string& nombre, Usuario& u);

    /** @brief Consulta el número de usuarios que pertenecen al parámetro implícito.
     
      \pre <em>cierto</em>
      \post El resultado retorna el número de usuarios que pertenecen al parámetro implícito actualmente.
      */
    int numero_usuarios() const;

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

private:
    map<string, Usuario> conj_u;
};
#endif
