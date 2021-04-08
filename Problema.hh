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
    @brief Representa un Problema de la Plataforma.

*/

class Problema
{
public:
    //Constructoras

    /** @brief Creadora con identificador de la clase Problema.

	\pre en "ID" se encuentra el identificador del problema
	\post El resultado es un nuevo Problema con identificador = ID.

    */
    Problema(string ID);

    //Destructora

    /** @brief  Destructora de la clase Problema.
	
	\pre <em>cierto</em>
	\post Se destruye el parametro implícito
    */
    ~Problema();

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
	\post Retorna el identificador del parametro implícito.
    */
    string obtener_id() const;

    /** @brief Consulta el ratio del Problema.

	\pre <em>cierto</em>
	\post Retorna el ratio del parametro implícito.
    */
    double obtener_ratio() const;

    /** @brief Consulta el numero de envios que tiene un Problema.
	
	\pre <em>cierto</em>
	\post Retorna el numero de envios totales que tiene el parametro implícito.
    */
    int envios_totales() const;

    //Escritura de Problema

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el número de envios totales, el numero de envios con exito de usuarios presentes o pasados y tambien escribe el ratio (t+1)/(e+1)

    */
    void escribir_problema() const;

/** @internal
private:
    string id;
    int env_totales, env_exito;
    double ratio;
    void actualizar_ratio();
*/
};

#endif
