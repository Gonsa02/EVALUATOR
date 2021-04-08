/**
    @mainpage EVALUATOR: plataforma de gestión de problemas y cursos de programación.
*/

#include "Plataforma.hh"
#include "Usuario.hh"
#include "Problema.hh"
#include "Sesion.hh"
#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** 
 @brief Programa principal para la <em>Gestión del EVALUATOR</em>.
 */

int main() {
    Plataforma p;
    p.leer_problemas_iniciales();
    p.leer_sesiones_iniciales();
    p.leer_cursos_iniciales();
    string c;
    cin >> c;
    while (c != "fin") {
	if (c == "nuevo_problema" or c == "np") {
	    string id_problema;
	    cin >> id_problema;
	    if (p.existe_problema(id_problema)) cout << "El problema ya existe" << endl;
	    else p.añadir_nuevo_problema(id_problema);
	}
	else if (c == "nueva_sesion" or c == "ns") {
	    string id_sesion;
	    cin >> id_sesion;
	    if (p.existe_sesion(id_sesion)) cout << "La sesión ya existe" << endl;
	    else p.añadir_nueva_sesion(id_sesion);
	}
	else if (c == "nuevo_curso" or c == "nc") p.añadir_nuevo_curso();
	else if (c == "alta_usuario") {
	    string nombre;
	    cin >> nombre;
	    if (p.existe_usuario(nombre)) cout << "El usuario ya existe" << endl;
	    else p.dar_alta_usuario(nombre);
	}
	else if (c == "baja_usuario") {
	    string nombre;
	    cin >> nombre;
	    if (p.existe_usuario(nombre)) p.dar_baja_usuario(nombre);
	    else cout << "El usuario no existe" << endl;
	}
	else if (c == "inscribir_curso" or c == "i") {
	    string nombre;
	    int id_curso;
	    cin >> nombre >> id_curso;
	    if (not p.existe_usuario(nombre) or p.usuario_cursando_curso(nombre) or not p.existe_curso(id_curso))
		cout << "El usuario no se puede inscribir_curso al curso" << endl;
	    else p.inscribir_curso(nombre, id_curso);
	}
	else if (c == "curso_usuario" or c == "cu") {
	    string nombre;
	    cin >> nombre;
	    if (not p.existe_usuario(nombre)) cout << "El usuario no existe" << endl;
	    else cout << p.curso_usuario(nombre) << endl;
	}
	else if (c == "sesion_problema" or c == "sp") {
	    int id_curso;
	    string id_problema;
	    if (not p.existe_curso(id_curso) or not p.existe_problema(id_problema)) 
		cout << "No se ha podido encontrar la sesión del problema" << endl;
	    else cout << p.sesion_problema(id_curso, id_problema) << endl;
	}
	else if (c == "problemas_resueltos" or c == "pr") {
	    string nombre;
	    cin >> nombre;
	    if (not p.existe_usuario(nombre)) cout << "El usuario no existe" << endl;
	    else p.escribir_problemas_resueltos_usuario(nombre);
	}
	else if (c == "problemas_enviables" or c == "pe") {
	    string nombre;
	    cin >> nombre;
	    if (not p.existe_usuario(nombre) or not p.usuario_cursando_curso(nombre)) 
		cout << "No se pueden escribir los problemas enviables" << endl;
	    else p.escribir_problemas_enviables_usuario(nombre);
	}
	else if (c == "envio" or c =="e") {
	    string nombre, id_problema;
	    int r;
	    cin >> nombre >> id_problema >> r;
	    p.envio(nombre, id_problema, r);
	}
	else if (c == "listar_problemas" or c =="lp") p.listar_problemas();
	else if (c == "escribir_problema" or c == "ep") {
	    string id_problema;
	    cin >> id_problema;
	    if (p.existe_problema(id_problema)) p.escribir_un_problema(id_problema);
	    else cout << "El problema no existe" << endl;
	}
	else if (c == "listar_sesiones" or c == "ls") p.listar_sesiones();
	else if (c == "escribir_sesion" or c == "es") {
	    string id_sesion;
	    cin >> id_sesion;
	    if (p.existe_sesion(id_sesion)) p.escribir_una_sesion(id_sesion);
	    else cout << "La sesion no existe" << endl;
	}
	else if (c == "listar_cursos" or c == "lc") p.listar_cursos();
	else if (c == "escribir_curso" or c == "ec") {
	    int id_curso;
	    cin >> id_curso;
	    if (p.existe_curso(id_curso)) p.escribir_un_curso(id_curso);
	    else cout << "El curso no existe" << endl;
	}
	else if (c == "listar_usuarios" or c == "lu") p.listar_usuarios();
	else if (c == "escribir_usuario" or c == "eu") {
	    string nombre;
	    cin >> nombre;
	    if (p.existe_usuario(nombre)) p.escribir_un_usuario(nombre);
	    else cout << "El usuario no existe" << endl;
	}
	cin >> c;
    }
}
