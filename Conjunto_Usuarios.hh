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

    \pre El Usuario "u" no existe en el parámetro implícito.
    \post Se ha añadido el Usuario "u" al parámetro implícito. 
    */
    void añadir(const Usuario& u);

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
