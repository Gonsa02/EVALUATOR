/**
    @mainpage EVALUATOR: plataforma de gestión de problemas y cursos de programación.
*/

#include "Conjunto_Usuarios.hh"
#include "Conjunto_Problemas.hh"
#include "Conjunto_Sesiones.hh"
#include "Conjunto_Cursos.hh"
#include "Usuario.hh"
#include "Problema.hh"
#include "Sesion.hh"
#include "Curso.hh"
#include "Operaciones_auxiliares.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** 
 @file main.cc
 @brief Programa principal para la <em>Gestión del EVALUATOR</em>.
 */

int main() {
    Conjunto_Usuarios conj_u;
    Conjunto_Problemas conj_p;
    Conjunto_Sesiones conj_s;
    Conjunto_Cursos conj_c;
    conj_p.inicializar();
    conj_s.inicializar();
    conj_c.inicializar();
    conj_u.inicializar();
    string c;
    cin >> c;
    while (c != "fin") {
	if (c == "nuevo_problema" or c == "np") {
	    Problema p;
	    p.leer();
	    cout << '#' << c << ' ' << p.obtener_id() << endl;
	    if (conj_p.existe(p)) cout << "error: el problema ya existe" << endl;
	    else {
		conj_p.anadir(p);
		cout << conj_p.tamano() << endl;
	    }
	}
	else if (c == "nueva_sesion" or c == "ns") {
	    Sesion s;
	    s.leer();
	    cout << '#' << c << ' ' << s.obtener_id() << endl;
	    if (conj_s.existe(s)) cout << "error: la sesion ya existe" << endl;
	    else {
		conj_s.anadir(s);
		cout << conj_s.tamano() << endl;
	    }
	}
	else if (c == "nuevo_curso" or c == "nc") {
	    Curso cur;
	    cur.leer();
	    cout << '#' << c << ' ' << cur.obtener_id() << endl;
	    if (conj_c.existe(cur)) cout << "El curso ya existe" << endl;
	    else if (cur.existe_interseccion(conj_s)) cout << "Hay interseccion en los problemas" << endl;
	    else {
		conj_c.anadir(cur);
		cout << conj_c.tamano() << endl;
	    }
	}
	else if (c == "alta_usuario" or c == "a") {
	    Usuario u;
	    u.leer();
	    cout << '#' << c << ' ' << u.obtener_nombre() << endl;
	    if (conj_u.existe(u)) cout << "error: el usuario ya existe" << endl;
	    else {
		conj_u.anadir(u);
		cout << conj_u.numero_usuarios() << endl;
	    }
	}
	else if (c == "baja_usuario" or c == "b") {
	    Usuario u;
	    u.leer();
	    cout << '#' << c << ' ' << u.obtener_nombre() << endl;
	    if (conj_u.existe(u)) {
		dar_baja(conj_u, conj_c, u);
		cout << conj_u.numero_usuarios() << endl;
	    }
	    else cout << "error: el usuario no existe" << endl;
	}
	else if (c == "inscribir_curso" or c == "i") {
	    Usuario u;
	    Curso cur;
	    u.leer();
	    cur.leer_id();
	    cout << '#' << c << ' ' << u.obtener_nombre() << ' ' << cur.obtener_id() << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else if (u.inscrito_a_curso()) cout << "error: usuario inscrito en otro curso" << endl;
	    else if (not conj_c.existe(cur)) cout << "error: el curso no existe" << endl;
	    else {
		inscribir_usuario_a_curso(conj_u, conj_c, conj_s, u, cur);
		conj_u.actualizar(u);
		conj_c.actualizar(cur);
		cout << cur.usuarios_actuales() << endl;
	    }
	}
	else if (c == "curso_usuario" or c == "cu") {
	    Usuario u;
	    u.leer();
	    cout << '#' << c << ' ' << u.obtener_nombre() << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else cout << u.curso() << endl;
	}
	else if (c == "sesion_problema" or c == "sp") {
	    Curso cur;
	    Problema p;
	    cur.leer_id();
	    p.leer();
	    cout << '#' << c << ' ' << cur.obtener_id() << ' ' << p.obtener_id() << endl;
	    if (not conj_c.existe(cur)) cout << "error: el curso no existe" << endl;
	    else if (not conj_p.existe(p)) cout << "error: el problema no existe" << endl;
	    else if (not cur.contiene_problema(p.obtener_id(), conj_s)) cout << "error: el problema no pertenece al curso" << endl;
	    else cout << cur.sesion_problema(p.obtener_id(), conj_s) << endl;
	}
	else if (c == "problemas_resueltos" or c == "pr") {
	    Usuario u;
	    u.leer();
	    cout << '#' << c << ' ' << u.obtener_nombre() << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else u.escribir_problemas_resueltos();
	}
	else if (c == "problemas_enviables" or c == "pe") {
	    Usuario u;
	    u.leer();
	    cout << '#' << c << ' ' << u.obtener_nombre() << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else if (not u.inscrito_a_curso()) cout << "error: usuario no inscrito en ningun curso" << endl;
	    else u.escribir_problemas_enviables();
	}
	else if (c == "envio" or c =="e") {
	    int r;
	    string nombre, id_problema;
	    cin >> nombre >> id_problema >> r;
	    envio(conj_u, conj_c, conj_p, conj_s, nombre, id_problema, r);
	}
	else if (c == "listar_problemas" or c =="lp") {
	    cout << '#' << c << endl;
	    conj_p.listar();
	}
	else if (c == "escribir_problema" or c == "ep") {
	    Problema p;
	    p.leer();
	    cout << '#' << c << ' ' << p.obtener_id() << endl;
	    if (conj_p.existe(p)) p.escribir_problema();
	    else cout << "error: el problema no existe" << endl;
	}
	else if (c == "listar_sesiones" or c == "ls") {
	    cout << '#' << c << endl;
	    conj_s.listar();
	}
	else if (c == "escribir_sesion" or c == "es") {
	    Sesion s;
	    s.leer_id();
	    cout << '#' << c << ' ' << s.obtener_id() << endl;
	    if (conj_s.existe(s)) s.escribir_sesion();
	    else cout << "error: la sesion no existe" << endl;
	}
	else if (c == "listar_cursos" or c == "lc") {
	    cout << '#' << c << endl;
	    conj_c.listar();
	}
	else if (c == "escribir_curso" or c == "ec") {
	    Curso cur;
	    cur.leer_id();
	    cout << '#' << c << ' ' << cur.obtener_id() << endl;
	    if (conj_c.existe(cur)) cur.escribir_curso();
	    else cout << "error: el curso no existe" << endl;
	}
	else if (c == "listar_usuarios" or c == "lu") {
	    cout << '#' << c << endl;
	    conj_u.listar();
	}
	else if (c == "escribir_usuario" or c == "eu") {
	    Usuario u;
	    u.leer();
	    cout << '#' << c << ' ' << u.obtener_nombre() << endl;
	    if (conj_u.existe(u)) u.escribir_usuario();
	    else cout << "error: el usuario no existe" << endl;
	}
	cin >> c;
    }
}
