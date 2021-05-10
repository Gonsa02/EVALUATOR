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
    
    /** @brief Consulta el identificador de una Sesion.

      \pre El parámetro implícito tiene un identificador asignado.
      \post Retorna el identificador del parámetro implícito.
    */
    void obtener_id(string& id_s) const;
    
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

    /** @brief Operación de lectura del identificador

      \pre En el canal standard de entrada se encuentra el identificador del parámetro implícito.
      \post Se ha añadido el identificador al parámetro implícito.
    */
    void leer_id();

private:
    int num_problemas;
    string id;
    BinTree<string> prerequisitos;

    void escribir_postorden(const BinTree<string> &arbol) const;
    void leer_bin_tree(BinTree<string>& a, const string& marca, int& num);
    void problemas_envio_i(const BinTree<string>& a, Conjunto_Usuarios& conj_u, const string& id_problema, bool& found) const;
    void problemas_enviables_i(const BinTree<string>& a, Conjunto_Usuarios& u) const;
    void anadir_problemas_a_curso_i(const BinTree<string>& a, Curso& c) const;
};

#endif
