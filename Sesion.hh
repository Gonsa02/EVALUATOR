/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <set>
#endif

/** @class Sesion
    @brief Representa una Sesion.

    Esta formada por diferentes problemas con strings identificadores y también cuenta con una estructura de relaciones de prerequisitos entre los diferentes problemas, donde todos los problemas son prerequisito directo de 0, 1 o 2 problemas excepto el primero.
*/

class Sesion
{
public:
    //Constructoras

    /** @brief Creadora por defecto de la clase Sesion.
     
	Se ejecuta automáticamente al declarar una Sesion.
	\pre <em>cierto</em>
	\post El resultado es un Sesion.
    */

    Sesion();

    //Destructora

    /** @brief  Destructora de la clase Sesion.
	
	\pre <em>cierto</em>
	\post Se destruye el parámetro implícito
    */
    ~Sesion();

    //Consultoras
    
    /** @brief Consulta el identificador de una Sesion.

      \pre El parámetro implícito tiene un identificador asignado.
      \post Retorna el identificador del parámetro implícito.
    */
    string obtener_id() const;
    
    /** @brief Consulta el número de Problemas que forman parte de la Sesion.

      \pre <em>cierto</em>
      \post La función retorna el número de Problemas que contiene el parametro implícito.
      */
    int numero_problemas() const;

    /** @brief Consulta el primer Problema de la Sesion.

      \pre <em>ciert</em>
      \post Devuelve el identificador del Problema inicial de la Sesion.
      */
    string problema_inicial() const;

    /** @brief Consulta a que problemas nos dará acceso el solucionar el Problema actual.

      \pre En el parámetro "id_problema" se encuentra el identificador del problema el cual queremos consultar los problemas sucesores. Existe un problema en el arbol con identificador = "id_problema".
      \post El resultado retorna un vector con los problemas que son sucesores del Problema, en caso que no haya problemas sucesores retorna un vector vacio.
      */
    vector<string> problemas_sucesores(string id_problema);

    /** @brief Consulta si hay intersección de problemas.

      \pre <em>Cierto</em>
      \post El resultado indica si la intersección es vacia entre el parámetro implícito y la Sesion "s".
    */

    bool interseccion_vacia(const Sesion & s) const;

    /** @brief Consulta si existe un Problema en la Sesion

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene el Problema que tiene el identificador "id"
      */
    bool contine_problema(string id) const;

    //Lectura y escritura

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el número de problemas que la forman, los identificadores de dichos problemas, siguiendo su estructura de prerequisitos en postorden.

    */
    void escribir_sesion() const;

    /** @brief Operación de lectura

      \pre En el canal standard de entrada se encuentra el identificador de la Sesion y la estructura de los prerequisitos de los problemas de la Sesion en preorden.
      \post Se ha añadido el identificador y la estructura de prerequisitos de problemas al parámetro implícito.
    */
    void leer();

    /** @brief Operación de lectura del identificador

      \pre En el canal standard de entrada se encuentra el identificador del parámetro implícito.
      \post Se ha añadido el identificador al parámetro implícito.
    */
    void leer_id();

private:
    string id;
    int num_problemas;
    BinTree<string> prerequisitos;
    set<string> conj_id_problemas;

    int calcular_nodos(BinTree<string> b);
    BinTree<string> subarbol(const BinTree<string> &arbol, string id_problema) const;
    void escribir_postorden(const BinTree<string> &arbol) const;
    void leer_bin_tree(BinTree<string>& a, set<string>& conj_id_problemas, string marca);
};

#endif
