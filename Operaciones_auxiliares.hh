/** @file Operaciones_auxiliares.hh
    @brief Módulo funcional auxiliar para el main.cc
*/

#ifndef _OPERACIONES_AUXILIARES_HH_
#define _OPERACIONES_AUXILIARES_HH_

#include "Problema.hh"
#include "Usuario.hh"
#include "Conjunto_Usuarios.hh"
#include "Conjunto_Cursos.hh"

#ifndef NO_DIAGRAM
#endif

/** @brief Da de baja a un Usuario.

    \pre El Usuario "u" existe en el Conjunto_Usuarios de "conj_u".
    \post El Usuario "u" ha sido eliminado del Conjunto_Usuarios "conj_u", tambíen se ha borrado de los registros del curso que actualmente estaba cursando en caso que estubiera cursando uno.
      */
void dar_baja(Conjunto_Usuarios& conj_u, Conjunto_Cursos& conj_c, const Usuario& u);

/** @brief Inscribe un Usuario a un Curso.
 
  \pre existe un Usuario "u" en el Conjunto_Usuarios, "u" está cursando un Curso actualmente y además el Curso "c" debe existir en el Conjunto_Cursos.
  \post El Usuario "u" ha sido inscrito al Curso "c", es decir, "u" consta de que está inscrito a un Curso y además de que ese Curso és "c". El Curso "c" consta de que hay un Usuario más que lo está cursando.
*/
void inscribir_usuario_a_curso(Usuario& u, Curso& c);

/** @brief Realiza un envio.
 
  \pre El Usuario "u" debe existir en el Conjunto_Usuarios y debe estar cursando un Curso "c" que contenga el Problema "p" (garantizado por el enunciado). En el parámetro "r" se encuentra un 1 si el envio ha sido solucionado con éxito o un 0 si es incorrecto.
  \post Se han actualizado las estadísticas de "u" y "p". Además si el resultado es 1 se han actualizado los problemas resueltos y enviables de "u" y se comprueba si con ello "u" ha completado el Curso, en caso afirmativo "u" deja de estar inscrito al Curso y en el Curso consta que un usuario lo ha finalizado. 
  */
void envio(Curso& c, Usuario& u, Problema& p, int r);

#endif

