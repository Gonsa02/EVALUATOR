/** @file Conjunto_Problemas.hh
    @brief Especificación de la clase Conjunto_Problemas
*/

#ifndef _CONJUNTO_PROBLEMAS_HH_
#define _CONJUNTO_PROBLEMAS_HH_

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <set>
#endif

/** @class Conjunto_Problemas
    @brief Representa un Conjunto de Problemas.
*/

class Conjunto_Problemas
{
public:

    //Modificadoras
    
    /** @brief Añade un Problema al Conjunto_Problemas.

    \pre El Problema "p" no existe en el parámetro implícito.
    \post Se ha añadido el Problema "p" al parámetro implícito. 
    */
    void anadir(const Problema& p);

    /** @brief Actualiza un Problema del Conjunto_Problemas

    \pre El Problema "p" existe en el parámetro implícito.
    \post Se ha sustituido el Problema "p" del parámetro implícito con el mismo identificador que "p" por "p".
    */
    void actualizar(const Problema& p);

    //Consultoras
    
    /** @brief Consulta si existe un Problema

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene el Problema "p", en caso de que exista "p" = al Problema "p" del parámetro implícito; en caso contrario, "p" no se modifica.
      */
    bool existe(Problema& p);

    /** @brief Obtiene un Problema del Conjunto_Problemas

	\pre Existe un Problema con identificador = "id_problema" en el parámetro implícito.
	\post En "p" se encuentra el Problema con identificador = "id_problema" del parámetro implícito.	
    */
    void obtener(const string& id_problema, Problema& p);

    /** @brief Consulta el número de problemas que tiene el Conjunto_Problemas

      \pre <em>cierto</em>
      \post Retorna el número de sesiones que tiene el parámetro implícito.
    */
    int tamano() const;

    //Lectura y Escritura

    /** @brief Lectura inicial de problemas.
    
      \pre En el canal standard de entrada estan preparados los diferentes problemas que se desea añadir inicialmente al Conjunto de Problemas.
      \post Se han añadido los Problemas al Conjunto de Problemas.
      */
    void inicializar();

    /** @brief Lista todos los problemas del Conjunto_Problemas
     
      \pre <em>cierto</em>
      \post Se han listado todos los problemas de la del parámetro implícito en orden creciente del ratio, indicando para cada uno el número de envios totales t, el número e de envíos con éxito a cada Problema, en ambos casos de usuarios presentes o pasados, se ha escrito el ratio (t+1)/(e+1). En caso de empate se han listado por orden creciente de identificador.
      */
    void listar() const;


private:
    map<string, Problema> conj_p;
};
#endif
