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
    void anadir(const string& id_p, const Problema& p);

    /** @brief Apunta el iterador a un Problema.
     
      \pre Existe un Problema con identificador = "id_p" en el parámetro implícito.
      \post El iterador del parámetro implícito apunta al Problema con identificador = "id_p".
      */
    void apuntar(const string& id_p);

    /** @brief Incrementa los envios totales de un Problema.

      \pre El iterador apunta a un Problema del parámetro implícito.
      \post Se ha incrementado en una unidad los envios totales del Problema el cual es apuntado por el iterador del parámetro implícito.
      */
    void incrementar_envios_totales_problema();

    /** @brief Incrementa los envios exitosos de un Problema.

      \pre El iterador apunta a un Problema del parámetro implícito.
      \post Se ha incrementado en una unidad los envios exitosos del Problema el cual es apuntado por el iterador del parámetro implícito.
      */
    void incrementar_envios_exitosos_problema();

    //Consultoras
    
    /** @brief Consulta si existe un Problema.

      \pre <em>cierto</em>
      \post El resultado indica si el parámetro implícito contiene el Problema con identificador = "id", en caso de que exista, el iterador del parámetro implícito apunta a ese Problema.
      */
    bool existe(const string& id);

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

    /** @brief Escribe un Problema del Conjunto_Problemas.

      \pre El iterador del parámetro implícito apunta a un Problema.
      \post Se ha escrito el número de envios totales, el número de envios con éxito de usuarios presentes o pasados y también se ha escrito el ratio (t+1)/(e+1) del Problema apuntado por el iterador del parámetro implícito.
      */
    void escribir_problema() const;


private:
    /** @brief Guarda el conjunto de Problemas con un diccionario que tiene como clave el identificador de un Problema y como valor la instáncia de la clase Problema con el mismo identificador que la clave del diccionario.*/
    map<string,Problema> conj_p;

    /** @brief Iterador interno de la clase Conjunto_Problemas.*/
    map<string,Problema>::iterator iterador;
};
#endif
