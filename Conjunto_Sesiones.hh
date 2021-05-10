/** @file Conjunto_Sesiones.hh
    @brief Especificación de la clase Conjunto_Sesiones
*/

#ifndef _CONJUNTO_SESIONES_HH_
#define _CONJUNTO_SESIONES_HH_

#include "Sesion.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Conjunto_Sesiones
    @brief Representa un Conjunto de Sesiones.
*/

class Conjunto_Sesiones
{
public:


    //Modificadoras
    
    /** @brief Añade una Sesion al Conjunto_Sesiones.

    \pre La Sesion "s" no existe en el parámetro implícito.
    \post Se ha añadido la Sesion "s" al parámetro implícito. 
    */
    void anadir(const string& id_s, const Sesion& s);

    /** @brief Apunta el iterador a una Sesion
     
      \pre Existe una Sesion con identificador = "id_s" en el parámetro implícito.
      \post El iterador del parámetro implícito apunta a la Sesion con identificador = "id_s".
      */
    void apuntar(const string& id_s);

    //Consultoras
    
    /** @brief Consulta si existe una Sesion con el mismo identificador.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene una Sesion con el mismo identificador y en ese caso el iterador del parámetro implícito apunta a esa Sesion.
      */
    bool existe(const string& id_s);

    /** @brief Consulta el número de sesiones que tiene el Conjunto_Sesiones

      \pre <em>cierto</em>
      \post Retorna el número de sesiones que tiene el parámetro implícito.
    */
    int tamano() const;

    /** @brief Consulta los problemas enviables y no resueltos de una Sesion y se los añade a un Usuario.

      \pre El iterador de conj_u apunta a un Usuario de su repositorio de Usuarios.
      \post Se han consultado y añadido los problemas enviables a los que tiene acceso el Usuario pero no los había resuelto de la sesión con identificador = "id_s".
      */
    void sesion_problemas_enviables_usuario(Conjunto_Usuarios& conj_u, const string& id_s) const;

    void sesion_problemas_envio_usuario(Conjunto_Usuarios& conj_u, const string& id_s, const string& id_p) const;

    /** @brief Añade los problemas de una Sesion a un Curso

      \pre El iterador del parámetro implícito apunta a una Sesion.
      \post Se han añadido los problemas de la Sesion apuntada por el parámetro implícito al Curso "c".
      */
    void anadir_problemas_a_curso(Curso& c) const;

    
    //Lectura y escritura

    /** @brief Lectura inicial de sesiones.
    
      \pre En el canal standard de entrada estan preparados las diferentes sesiones que se desea añadir inicialmente al conjunto de sesiones.
      \post Se han añadido los problemas al conjunto de problemas.
      */
    void inicializar();

    /** @brief Lista todas las sesiones del Conjunto_Sesiones.
     
      \pre <em>cierto</em>
      \post Se han listado todas las sesiones del parametro implícito ordenadas crecientemente por su identificador y mostrando, para cada sesión, el número de problemas que la forman y los identificadores de dichos problemas, siguiendo su estructura de prerequisitos en postorden.
      */
    void listar() const;    

    /** @brief Escribe una Sesion.
     
      \pre El iterador del parámetro implícito apunta a una Sesion.
      \post Escribe el número de problemas forman la Sesion apuntada por el identificador del parámetro implícito, los identificadores de dichos problemas, siguiendo su estructura de prerequisitos en postorden.
      */
    void escribir_sesion() const;

private:
    map<string,Sesion> conj_s;
    map<string,Sesion>::const_iterator iterador;
};
#endif
