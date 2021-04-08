/** @file Plataforma.hh
    @brief Especificación de la clase Plataforma
*/

#ifndef _PLATAFORMA_HH_
#define _PLATAFORMA_HH_

#include "Usuario.hh"
#include "Problema.hh"
#include "Sesion.hh"
#include "Curso.hh"

#ifndef NO_DIAGRAM
#endif

/** @class Plataforma
    @brief Representa la Plataforma de Cursos

    La clase Plataforma es la encargada de gestionar todas las operaciones y tipos de datos que va a tener nuestro programa. A través de ella se va a manejar la mayoria de la lógica del programa principal. Además será la encargada de gestionar los repositorios de los problemas, sesiones, cursos y usuarios.
*/

class Plataforma
{
public:

    //Constructoras
    
    /** @brief Creadora por defecto de la clase Plataforma.
     
	Se ejecuta automáticamente al declarar una Plataforma.
	\pre <em>cierto</em>
	\post El resultado es una Plataforma.
    */

    Plataforma();

    //Destructora

    /** @brief Destructora de la clase Plataforma.

      \pre <em>cierto</em>
      \post Se destruye el parametro implícito
    */
    ~Plataforma();

    //Modificadoras
    
    /** @brief Añade un nuevo Problema a la Plataforma.
    
      \pre En el parámetro id_problema se encuentra el identificador del problema que queremos añadir al repositorio del parámetro implícito. El problema no debe existir en la plataforma.
      \post Se ha añadido el Problema a los repositorios del parámetro implícito.
      */
    void añadir_nuevo_problema(string id_problema);
    
    /** @brief Añade una nueva Sesion a la Plataforma.
    
      \pre En el parámetro id_sesion se encuentra el identificador de la Sesion que queremos añadir al repositorio del parámetro implícito. Además también está preparada para leer la estructura de problemas de la Sesion. La Sesion no debe existir en la plataforma.
      \post Se ha añadido la Sesion a los repositorios del parámetro implícito y se ha escrito el número de sesiones que hay en el repositorio después de añadir la nueva Sesion.
      */
    void añadir_nueva_sesion(string id_sesion);

    /** @brief Añade un nuevo Curso a la Plataforma.

    \pre En el canal de entrada estandar hay preparadas un número de sesiones S > 0 seguidas de una secuencia de S identificadorews válidos de seiones. La intersección de los problemas de las sesiones debe ser nula.
    \post Si la intersección de los problemas de las sesiones era nula, el problema se ha añadido correctamente al respositorio del parámetro implícito con id = N+1, en caso contrario no se ha añadido y se ha imprimido un mensaje de error.
    */
    void añadir_nuevo_curso();

    /** @brief Da de alta a un nuevo Usuario.

      \pre En el el parámetro "nombre" se encuentra el nombre que tendrá el nuevo Usuario en la Plataforma. No existe ningún otro usuario con nombre = "nombre".
      \post El Usuario ha quedado registrado en el parámetro implícito y se ha imprimido el número de usuarios registrados actualmente.
      */
    void dar_alta_usuario(string nombre);

    /** @brief Da de baja a un Usuario.

      \pre En el el parámetro "nombre" se encuentra el nombre del Usuario que deseamos eliminar del registo de la Plataforma. Existe un usuario con nombre = "nombre".
      \post El Usuario ha sido eliminado del registro de usuarios del parametro implícito, tambíen se ha borrado de los registros del curso que actualmente estaba cursando en caso que estubiera cursando uno.
      */
    void dar_baja_usuario(string nombre);

    /** @brief Inscribe un Usuario a un Curso.

      \pre En el el parámetro "nombre" se encuentra el nombre del Usuario en la Plataforma y en id_curso se encuentra el identificador del curso al cual lo queremos inscribir. Debe existir un Usuario con nombre = "nombre" y también un curso con identificador = "id_curso".
      \post El Usuario con nombre = "nombre" ha sido inscrito al curso con identificador = "id_curso" y se ha imprimido el número de usuarios inscritos en el Curso después de añadirlo.
      */
    void inscribir_curso(string nombre, int id_curso);

    /** @brief El Usuario hace un envio.

      \pre El Usuario con nombre = "nombre" debe existir y debe estar cursando un Curso que contenga el Problema con identificador = "id_problema" (garantizado por el enunciado). En el parámetro "resultado" hay un 1 si lo ha solucionado con éxito o un 0 si es incorrecto.
      \post Se han actualizado las estadísticas del usuario y del problema. Además si resultado = 1 se han actualizado los problemas resueltos y enviables del Usuario y si con ello ha completado el Curso, el Usuario deja de estar inscrito en ese Curso.
    */
    void envio(string nombre, string id_problema, int resultado);

    //Consultoras

    /** @brief Consulta si existe un Problema en el repositorio del parametro implícito.

      \pre En el parámetro "id_problema" se encuentra el identificador del Problema el cual queremos comprobar si está o no en el repositorio de problemas del parametro implícito.
      \post El resultado indica si existe el Problema en el repositorio del parametro implícito.
      */
    bool existe_problema(string id_problema) const;


    /** @brief Consulta si existe una Sesion en el repositorio del parametro implícito.

      \pre En el parámetro "id_sesion" se encuentra el identificador de la Sesion la cual queremos comprobar si está o no en el repositorio de sesiones del parametro implícito.
      \post El resultado indica si existe la Sesion en el repositorio del parametro implícito.
      */
    bool existe_sesion(string id_sesion) const;


    /** @brief Consulta si existe un Curso en el repositorio del parametro implícito.

      \pre En el parámetro "id_curso" se encuentra el identificador del Curso el cual queremos comprobar si está o no en nuestro repositorio de cursos del parametro implícito.
      \post El resultado indica si existe el Curso en el repositorio del parametro implícito.
      */
    bool existe_curso(int id_curso) const;


    /** @brief Consulta si existe un Usuario dado de alta en el Curso.

      \pre En el parámetro "nombre" se encuentra el nombre del Usuario el cual queremos comprobar si está o no dado de alta en el parametro implícito.
      \post El resultado indica si existe el usuario con nombre = "nombre" está dado de alta en el parametro implícito.
      */
    bool existe_usuario(string nombre) const;

    /** @brief Consulta si un Usuario está cursando un Curso.

    \pre En el parámetro "nombre" se encuentra el nombre del Usuario el cual queremos comprobar si está inscrito acutalmente en algun Curso del parámetro implícito. El Usuario con nombre = "nombre" debe existir.
    \post El resultado indica si el Usuario con nombre = "nombre" está cursando actualmente algun curso.
    */
    bool usuario_cursando_curso(string nombre) const;

    /** @brief Consulta que Curso está cursando un Usuario

      \pre En el parámetro "nombre" se encuentra el nombre del Usuario el cual queremos saber a que curso está inscrito. Debe existir un Usuario con nombre = "nombre".
      \post Retorna el identificador del Curso que está cursando el Usuario en el parametro implícito.
      */
    string curso_usuario(string nombre) const;

    /** @brief Consulta en que Sesion se encuentra un Problema en un determinado Curso.

      \pre En el parámetro "id_curso" se encuentra el identificador en el cual queremos buscar a que Sesion pertenece el Problema con identificador = "id_problema". Debe existir un curso con identificador = "id_curso" y un problema en el curso con identificador = "id_problema".
      \post Retorna el identificador de la Sesion del parámetro implícito en la que se encuentra el Problema con identificador = "id_problema" en el Curso con identificador = "id_curso".
      */
    string sesion_problema(int id_curso, string id_problema);

    /** @brief Escribe un Problema de la Plataforma.
     
      \pre En el parámetro "id_problema" se encuentra el identificador del Problema que queremos escribir. Debe existir un Problema con identificador = "id_problema".
      \post Se ha escrito el Problema con identificador = "id_problema" del parametro implícito el número de envios totales t, el número e de envíos con éxito a cada problema, en ambos casos de usuarios presentes o pasados, se ha escrito el ratio (t+1)/(e+1). En caso de empate se han listado por orden creciente de identificador.
      */
    //La clase Problema cuenta con un método para escribirse.
    void escribir_un_problema(string id_problema) const;

    /** @brief Lista todos los problemas de la Plataforma.
     
      \pre <em>cierto</em>
      \post Se han listado todos los problemas de la colección del parametro implícito en orden creciente del ratio, indicando para cada uno el número de envios totales t, el número e de envíos con éxito a cada Problema, en ambos casos de usuarios presentes o pasados, se ha escrito el ratio (t+1)/(e+1). En caso de empate se han listado por orden creciente de identificador.
      */
    //La clase Problema cuenta con un método para escribirse.
    void listar_problemas() const;


    /** @brief Escribe una Sesion de la Plataforma.
     
      \pre En el parámetro "id_sesion" se encuentra el identificador de la Sesion que queremos escribir. Debe existir una Sesion con identificador = "id_sesion".
      \post Se ha escrito la Sesion con identificador = "id_sesion" del parametro implícito escribiendo el número de problemas que la forman y los identificadores de dichos problemas, siguiendo su estructura de prerequisitos en postorden.
      */
    //La clase Sesion cuenta con un método para escribirse.
    void escribir_una_sesion(string id_sesion) const;    

    /** @brief Lista todas las sesiones de la Plataforma.
     
      \pre <em>cierto</em>
      \post Se han listado todas las sesiones del parametro implícito ordenadas crecientemente por su identificador y mostrando, para cada sesión, el número de problemas que la forman y los identificadores de dichos problemas, siguiendo su estructura de prerequisitos en postorden.
      */
    //La clase Sesion cuenta con un método para escribirse.
    void listar_sesiones() const;    


    /** @brief Escribe un Curso de la Plataforma.
     
      \pre En el parámetro "id_curso" se encuentra el identificador del Curso que queremos escribir. Debe existir una Sesion con identificador = "id_sesion".
      \post Se ha escrito el Curso del parametro implícito con el numero de usuarios actualos o pasados que lo han completado, el numero de usuarios inscritos actualmente, el numero de sesiones qeu lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el Curso.
      */
    //La clase Curso cuenta con un método para escribirse.
    void escribir_un_curso(int id_curso) const;    


    /** @brief Lista todos los cursos de la Plataforma.
     
      \pre <em>cierto</em>
      \post Para cada Curso que haya en el parametro implícito, se escribe el numero de usuarios actualos o pasados que lo han completado, el numero de usuarios inscritos actualmente, el numero de sesiones qeu lo forman y los identificadores de dichas sesiones, en el mismo orden en el que se leyeron cuando se creó el Curso.
      */
    //La clase Curso cuenta con un método para escribirse.
    void listar_cursos() const;    

    /** @brief Escribe un Usuario registrado actualmente en la Plataforma.

      \pre En el parámetro "nombre" se encuentra el nombre del Usuario que queremos escribir. Debe existir un Usuario con nombre = "nombre".
      \post Se ha escrito el Usuario con identificador = nombre del parametro implícito. Ha escrito cuantos envios en total ha realizado, cuantos problemas ha resuelto, cuentos ha intentado resolver y el id del curso en el cual está inscrito o cero si no está inscrito en ninguno.
    */
    //La clase Usuario cuenta con un método para escribirse.
    void escribir_un_usuario(string nombre) const;

    /** @brief Lista todos los usuarios registrados actualmente en la Plataforma.

      \pre <em>cierto</em>
      \post Para cada Usuario registrado en el parametro implícito, escribe cuantos envios en total ha realizado, cuantos problemas ha resuelto, cuentos ha intentado resolver y el id del curso en el cual está inscrito o cero si no está inscrito en ninguno.
    */
    //La clase Usuario cuenta con un método para escribirse.
    void listar_usuarios() const;

    //Lectura

    /** @brief Lectura inicial de problemas.
    
      \pre En el canal standard de entrada estan preparados los diferentes problemas que se desea añadir a la Plataforma de cursos.
      \post Se han añadido los problemas a los repositorios del parametro implícito.
      */
    void leer_problemas_iniciales();

    /** @brief Lectura inicial de sesiones.
    
      \pre En el canal standard de entrada estan preparadas las diferentes sesiones de las que va a constar inicialmente la Plataforma de cursos.
      \post Se han añadido las sesiones a los repositorios del parametro implícito.
      */
    void leer_sesiones_iniciales();

    /** @brief Lectura inicial de usuarios.
    
      \pre En el canal standard de entrada estan preparados los diferentes usuarios de los que va a constar inicialmente la Plataforma de cursos.
      \post Se han añadido los usuarios a los registros del parametro implícito.
      */
    void leer_usuarios_iniciales();

    /** @brief Lectura inicial de cursos.
    
      \pre En el canal standard de entrada estan preparados los diferentes cursos de los que va a constar inicialmente la Plataforma de cursos.
      \post Se han añadido los cursos al repositorio de cursos del parametro implícito.
      */
    void leer_cursos_iniciales();


    //Escritura

    /** @brief Escribe los problemas resueltos por un Usuario.
    
	\pre En el parámetro "nombre" se encuentra el identificador del Usuario el cual queremos escribir los problemas resueltos. El Usuario con identificador = "nombre" debe existir.
	\post Se han escrito por orden creciente por identificador los problemas solucionados con éxito por el usuario con nombre = "nombre".
    */
    void escribir_problemas_resueltos_usuario(string nombre);

    /** @brief Escribe los problemas resueltos por un Usuario.
    
	\pre En el parámetro "nombre" se encuentra el identificador del Usuario el cual queremos escribir los problemas enviables. El Usuario con identificador = "nombre" debe existir.
	\post Se han escrito por orden creciente por identificador los problemas solucionados con éxito por el usuario con nombre = "nombre".
    */
    void escribir_problemas_enviables_usuario(string nombre);

};
#endif
