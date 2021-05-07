/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_
#include "Usuario.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <set>
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

    /** @brief Consulta los problemas enviables y no resueltos que tiene un Usuario y se los añade.
     
      \pre <em>cierto</em>
      \post Se han consultado y añadido los problemas enviables a los que tiene acceso el Usuario pero no los había resuelto.
    */
    void problemas_enviables(Usuario& u) const;

    /** @brief Consulta los problemas enviables y no resueltos que tiene un Usuario a partir de un Problema y se los añade.

    \pre <em>cierto</em>
    \post Se han consultado y añadido los problemas enviables a los que tiene acceso  el Usuario pero no los había resuelto a partir de un Problema.
    */
    void problemas_envio(Usuario& u, string id_problema) const;

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

    // Iterador

    /** @brief Inizializa el iterador de problemas al inicio de la Sesion.
    
      \pre <em>cierto</em>
      \post El iterador del parámetro implícito apunta al primer Problema del parámetro implícito.
    */
    void inizializar_iterador();

    /** @brief Icrementa el iterador para que apunte al siguiente Problema del parámetro implícito.
    
      \pre El iterador no apunta al elemento end().
      \post El iterador del parámetro implícito apunta al siguiente Problema del parámetro implícito.
    */
    void incrementar_iterador();

    /** @brief Consulta si el iterador ya ha llegado al final.

      \pre <em>cierto</em>
      \post Retorna si el iterador apunta al último elemento del parámetro implícito o no.
    */
    bool end() const;

    /** @brief Consulta el valor al qual apunta el iterador de la Sesion.

      \pre El iterador apunta a un Problema del parámetro implícito.
      \post Retorna el identificador del Problema al cual apunta el iterador del parámetro implícito.
    */
    string valor() const;

private:
    string id;
    int num_problemas;
    BinTree<string> prerequisitos;
    set<string> conj_id_problemas;
    set<string>::const_iterator iterador_problemas;

    void escribir_postorden(const BinTree<string> &arbol) const;
    void leer_bin_tree(BinTree<string>& a, set<string>& conj_id_problemas, string marca);
    void problemas_envio_i(const BinTree<string>& a, Usuario& u, string id_problema, bool& found) const;
    void problemas_enviables_i(const BinTree<string>& a, Usuario& u) const;
};

#endif
