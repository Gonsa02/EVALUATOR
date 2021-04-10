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
	    if (conj_p.existe(p)) cout << "El problema ya existe" << endl;
	    else conj_p.añadir(p);
	}
	else if (c == "nueva_sesion" or c == "ns") {
	    Sesion s;
	    s.leer();
	    if (conj_s.existe(s)) cout << "La sesión ya existe" << endl;
	    else conj_s.añadir(s);
	}
	else if (c == "nuevo_curso" or c == "nc") {
	    Curso c;
	    c.leer();
	    if (conj_c.existe(c)) cout << "El curso ya existe" << endl;
	    else if (c.existe_interseccion()) cout << "Hay interseccion en los problemas" << endl;
	    else conj_c.añadir(c);
	}
	else if (c == "alta_usuario") {
	    Usuario u;
	    u.leer();
	    if (conj_u.existe(u)) cout << "El usuario ya existe" << endl;
	    else {
		conj_u.añadir(u);
		cout << conj_u.numero_usuarios() << endl;
	    }
	}
	else if (c == "baja_usuario") {
	    Usuario u;
	    u.leer();
	    if (conj_u.existe(u)) {
		dar_baja(conj_u, conj_c, u);
		cout << conj_u.numero_usuarios() << endl;
	    }
	    else cout << "El usuario no existe" << endl;
	}
	else if (c == "inscribir_curso" or c == "i") {
	    Usuario u;
	    Curso c;
	    u.leer();
	    c.leer_id();
	    if (not conj_u.existe(u) or u.inscrito_a_curso() or not conj_c.existe(c))
		cout << "El usuario no se puede inscribir al curso" << endl;
	    else inscribir_usuario_a_curso(u, c);
	}
	else if (c == "curso_usuario" or c == "cu") {
	    Usuario u;
	    u.leer();
	    if (not conj_u.existe(u)) cout << "El usuario no existe" << endl;
	    else cout << u.curso() << endl;
	}
	else if (c == "sesion_problema" or c == "sp") {
	    Curso c;
	    Problema p;
	    c.leer_id();
	    p.leer();
	    if (conj_c.existe(c) or not conj_p.existe(p)) 
		cout << "No se ha podido encontrar la sesión del problema" << endl;
	    else cout << c.sesion_problema(p.obtener_id()) << endl;
	}
	else if (c == "problemas_resueltos" or c == "pr") {
	    Usuario u;
	    u.leer();
	    if (not conj_u.existe(u)) cout << "El usuario no existe" << endl;
	    else u.escribir_problemas_resueltos();
	}
	else if (c == "problemas_enviables" or c == "pe") {
	    Usuario u;
	    u.leer();
	    if (conj_u.existe(u) or not u.inscrito_a_curso()) 
		cout << "No se pueden escribir los problemas enviables" << endl;
	    else u.escribir_problemas_enviables();
	}
	else if (c == "envio" or c =="e") {
	    int r;
	    string nombre, id_problema;
	    cin >> nombre >> id_problema >> r;
	    Curso c;
	    Usuario u;
	    Problema p;
	    conj_u.obtener(nombre, u);
	    conj_c.obtener_con_id(u.curso(), c);
	    conj_p.obtener(id_problema, p);
	    envio(c, u, p, r);
	}
	else if (c == "listar_problemas" or c =="lp") conj_p.listar();
	else if (c == "escribir_problema" or c == "ep") {
	    Problema p;
	    p.leer();
	    if (conj_p.existe(p)) p.escribir_problema();
	    else cout << "El problema no existe" << endl;
	}
	else if (c == "listar_sesiones" or c == "ls") conj_s.listar();
	else if (c == "escribir_sesion" or c == "es") {
	    Sesion s;
	    s.leer_id();
	    if (conj_s.existe(s)) s.escribir_sesion();
	    else cout << "La sesion no existe" << endl;
	}
	else if (c == "listar_cursos" or c == "lc") conj_c.listar();
	else if (c == "escribir_curso" or c == "ec") {
	    Curso c;
	    c.leer_id();
	    if (conj_c.existe(c)) c.escribir_curso();
	    else cout << "El curso no existe" << endl;
	}
	else if (c == "listar_usuarios" or c == "lu") conj_u.listar();
	else if (c == "escribir_usuario" or c == "eu") {
	    Usuario u;
	    u.leer();
	    if (conj_u.existe(u)) u.escribir_usuario();
	    else cout << "El usuario no existe" << endl;
	}
	cin >> c;
    }
}
