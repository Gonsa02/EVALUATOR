/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#endif

/** @class Sesion
    @brief Representa una Sesion.

    Esta formada por diferentes problemas con strings identificadores y también cuenta con una estructura de relaciones de prerequisitos entre los diferentes problemas, donde todos los problemas son prerequisito directo de 0, 1 o 2 problemas excepto el primero.
*/

class Sesion
{
public:
    //Constructoras

    /** @brief Creadora de la clase Sesion con identificador y con estructura de prerequisitos.
	
	\pre En "id_sesion" se encuentra el identificador de la Sesion y en el parámetro b se encuentra la estructura de prerequisitos de problemas de la Sesion.
	\post El resultado es una Sesion con identificador "id_sesion" y con la estructura de prerequisitos que se encuentra en b.
    */

    Sesion(string id_sesion, BinTree<string> b);

    //Destructora

    /** @brief  Destructora de la clase Sesion.
	
	\pre <em>cierto</em>
	\post Se destruye el parametro implícito
    */
    ~Sesion();

    //Consultoras
    
    /** @brief Consulta el número de Problemas que forman parte de la Sesion.

      \pre <em>cierto</em>
      \post La función retorna el número de Problemas que contiene el parametro implícito.
      */
    int numero_problemas() const;

    /** @brief Consulta a que problemas nos dará acceso el solucionar el Problema actual.

      \pre En el parámetro "id_problema" se encuentra el identificador del problema el cual queremos consultar los problemas sucesores. Existe un problema en el arbol con identificador = "id_problema".
      \post El resultado retorna un vector con los problemas que son sucesores del Problema, en caso que no haya problemas sucesores retorna un vector vacio.
      */
    vector<string> problemas_sucesores(string id_problema);

    //Lectura y escritura

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el número de problemas que la forman, los identificadores de dichos problemas, siguiendo su estructura de prerequisitos en postorden.

    */
    void escribir_sesion() const;

/** @internal
private:
    string id;
    int num_problemas;
    BinTree<string> prerequisitos;
    int calcular_nodos(BinTree<string> b);
    BinTree<string> subarbol(const BinTree<string> &arbol, string id_problema) const;
    void postorden(const BinTree<string> &arbol) const;
    */
};

#endif
