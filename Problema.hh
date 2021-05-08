/** @file Problema.hh
    @brief Espeficiación de la clase Problema
*/


#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Problema
    @brief Representa un Problema.

*/

class Problema
{
public:
    //Constructoras

    /** @brief Creadora por defecto de la clase Problema.
     
	Se ejecuta automáticamente al declarar un Problema.
	\pre <em>cierto</em>
	\post El resultado es un Problema.
    */

    Problema();

    //Modificadoras

    /** @brief Incrementa el número de envios totales de un Problema.

      \pre <em>cierto</em>
      \post Se ha añadido un envio total al parámetro implícito.
    */
    void incrementar_envios_totales();


    /** @brief Incrementa el número de envios con éxito de un Problema.

      \pre <em>cierto</em>
      \post Se ha añadido un envio con éxito al parámetro implícito.
    */
    void incrementar_envios_exitosos();


    //Consultoras

    /** @brief Consulta el identificador del Problema.

	\pre <em>cierto</em>
	\post "id_p" = el identificador del parametro implícito.
    */
    void obtener_id(string& id_p) const;

    //Escritura i lectura de Problema

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el número de envios totales, el numero de envios con exito de usuarios presentes o pasados y tambien escribe el ratio (t+1)/(e+1)

    */
    void escribir_problema() const;

    /** @brief Operación de lectura

      \pre En el canal standard de entrada se encuentra el identificador del Problema.
      \post Se ha añadido el identificador al parámetro implícito.
    */
    void leer();

    // Comparadoras

    /** @brief Operación de comparación del Problema

     \pre <em>cierto</em>
     \post El resultado indica si el parámetro implícito es menor que el Problema "p".
    */
    bool operator<(const Problema &p) const;

private:
    string id;
    int env_totales, env_exito;
    double ratio;
    void actualizar_ratio();
};

#endif
