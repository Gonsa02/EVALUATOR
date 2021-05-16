/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_
#include "Conjunto_Usuarios.hh"
#include "Curso.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/** @class Sesion
    @brief Representa una Sesion.

*/

class Sesion
{
public:

    //Constructoras
    
    /** @brief Crea una Sesion con identificador;

     \pre <em>cierto</em>
     \post El resultado es una Sesion con identificador = "id_s"
     */
    Sesion(const string& id_s);

    //Consultoras
    
    /** @brief Consulta los problemas enviables y no resueltos que tiene un Usuario y se los añade.
     
      \pre <em>cierto</em>
      \post Se han consultado y añadido los problemas enviables a los que tiene acceso el Usuario apuntado por el iterador del Conjunto de Usuarios pero que no los había resuelto.
    */
    void problemas_enviables(Conjunto_Usuarios& conj_u) const;

    /** @brief Consulta los problemas enviables y no resueltos que tiene un Usuario a partir de un Problema y se los añade.

    \pre <em>cierto</em>
    \post Se han consultado y añadido al Usuario apuntado por el iterador del Conjunto_Usuarios los problemas enviables a los que tiene acceso el Usuario pero no los había resuelto a partir de un Problema.
    */
    void problemas_envio(Conjunto_Usuarios& conj_u, const string& id_problema) const;

    /** @brief Añade los problemas de la Sesion a un Curso

      \pre <em>cierto</em>
      \post Se han añadido los problemas del parámetro implícito al Curso "c".
      */
    void anadir_problemas_a_curso(Curso& c) const;

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

private:
    /** @brief Guarda el número de problemas que tiene una Sesion.*/
    int num_problemas;

    /** @brief Guarda el identificador de una Sesion.*/
    string id;

    /** @brief Guarda la estructura de prerequisitos de los problemas de la Sesion.*/
    BinTree<string> prerequisitos;

    /** @brief Operación de escritura de la estructura de prerequisitos de la Sesion

      \pre <em>cierto</em>
      \post Se ha escrito en postorden la estructura de prerequisitos del parámetro implícito.
    */
    void escribir_postorden(const BinTree<string> &arbol) const;

    /** @brief Operación de lectura de la estructura de prerequisitos de la Sesion

      \pre <em>cierto</em>
      \post Se ha leido en preorden la estructura de prerequisitos de la Sesion y se ha añadido al parámetro implícito.
      */
    void leer_bin_tree(BinTree<string>& a, const string& marca, int& num);

    /** @brief Función de immersión para el método problemas envio.

      \pre El iterador del Conjunto_Usuarios apunta a un Usuario.
      \post Primero se ha buscado el subarbol de "a" que tiene como raíz el "id_problema" y luego se han consultado y añadido al Usuario apuntado por el iterador del Conjunto_Usuarios los problemas enviables a los que tiene acceso el Usuario pero no los había resuelto a partir de un Problema.
      */
    void problemas_envio_i(const BinTree<string>& a, Conjunto_Usuarios& conj_u, const string& id_problema, bool& found) const;
    
    /** @brief Consulta los problemas a los que tiene acceso un Usuario y se los añade.

      \pre El iterador del Conjunto_Usuarios aputna a un Usuario.
      \post Se han consultado y añadido al Usuario apuntado por el iterador del Conjunto_Usuarios los problemas enviables a los que tiene acceso el Usuario pero no los había resuelto a partir de un Problema.
    */
    void obtener_problemas_enviables_i(const BinTree<string>& a, Conjunto_Usuarios& u) const;

    /** @brief Añade los problemas de una Sesion a un Curso.
      \pre <em>cierto</em>
      \post Se han añadido los problemas de los que consta la Sesion al Curso.
      */
    void anadir_problemas_a_curso_i(const BinTree<string>& a, Curso& c) const;
};

#endif
