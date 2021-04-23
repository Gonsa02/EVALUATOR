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
    //Constructoras
    
    /** @brief Creadora por defecto de la clase Conjunto_Sesiones.
     
	Se ejecuta automáticamente al declarar un Conjunto_Sesiones.
	\pre <em>cierto</em>
	\post El resultado es un Conjunto de Sesiones.
    */

    Conjunto_Sesiones();

    //Destructora

    /** @brief Destructora de la clase Conjunto_Sesiones.

      \pre <em>cierto</em>
      \post Se destruye el parametro implícito.
    */
    ~Conjunto_Sesiones();

    //Modificadoras
    
    /** @brief Añade una Sesion al Conjunto_Sesiones.

    \pre La Sesion "s" no existe en el parámetro implícito.
    \post Se ha añadido la Sesion "s" al parámetro implícito. 
    */
    void añadir(const Sesion& s);

    //Consultoras
    
    /** @brief Consulta si existe una Sesion con el mismo identificador.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene una Sesion "s" con el mismo identificador y en caso, "s" = Sesion del parámetro implícito con el mismo identificador, en caso contrario "s" no se modifica.
      */
    bool existe(Sesion& s);

    
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

private:
    map<string, Sesion> conj_s;
};
#endif
