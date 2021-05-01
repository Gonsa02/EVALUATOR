/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_


#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <set>
#include <iostream>
#endif

/** @class Sesion
    @brief Representa una Sesion.

    Esta formada por diferentes problemas con strings identificadores y también cuenta con una estructura de relaciones de prerequisitos entre los diferentes problemas, donde todos los problemas son prerequisito directo de 0, 1 o 2 problemas excepto el primero.
*/

class Sesion
{
public:

    //Consultoras
    
    /** @brief Consulta el identificador de una Sesion.

      \pre El parámetro implícito tiene un identificador asignado.
      \post Retorna el identificador del parámetro implícito.
    */
    string obtener_id() const;
    
    /** @brief Consulta el primer Problema de la Sesion.

      \pre <em>cierto</em>
      \post Devuelve el identificador del Problema inicial de la Sesion.
      */
    string problema_inicial() const;

    /** @brief Consulta a que problemas nos dará acceso el solucionar el Problema actual.

      \pre En el parámetro "id_problema" se encuentra el identificador del problema el cual queremos consultar los problemas sucesores. Existe un problema en el arbol con identificador = "id_problema".
      \post El método retorna el valor de sucesores que tenia el problema. En caso que tenga 2 sucesores, estos se encuentran en sucesor_1 y sucesor_2; en caso de que solo haya un sucesor, este se encuentra en sucesor_1.
      */
    int problemas_sucesores(string id_problema, string& sucesor_1, string& sucesor_2) const;

    /** @brief Consulta si hay intersección de problemas.

      \pre <em>Cierto</em>
      \post El resultado indica si la intersección es vacia entre el parámetro implícito y la Sesion "s".
    */

    bool interseccion_vacia(const Sesion & s) const;

    /** @brief Consulta si existe un Problema en la Sesion

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene el Problema que tiene el identificador "id"
      */
    bool contiene_problema(string id) const;

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

    // Comparadoras
    
    /** @brief Operación de comparación de la Sesion

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito es menor que la Sesion "s".
      */
    bool operator<(const Sesion& s) const;

private:
    string id;
    int num_problemas;
    BinTree<string> prerequisitos;
    set<string> conj_id_problemas;

    void escribir_postorden(const BinTree<string> &arbol) const;
    void leer_bin_tree(BinTree<string>& a, set<string>& conj_id_problemas, string marca);
    int problemas_sucesores_i(const BinTree<string>& a, string id_problema, string& sucesor_1, string& sucesor_2) const;
};

#endif
