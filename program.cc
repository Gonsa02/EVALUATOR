/**
    @mainpage EVALUATOR: plataforma de gestión de problemas y cursos de programación.
*/

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

#include "Conjunto_Problemas.hh"
#include "Conjunto_Cursos.hh"
#include "Conjunto_Usuarios.hh"


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
    conj_c.inicializar(conj_s);
    conj_u.inicializar();
    string c;
    cin >> c;
    while (c != "fin") {
	if (c == "nuevo_problema" or c == "np") {
	    string id;
	    cin >> id;
	    Problema p(id);
	    cout << '#' << c << ' ' << id << endl;
	    if (conj_p.existe(id)) cout << "error: el problema ya existe" << endl;
	    else {
		conj_p.anadir(id, p);
		cout << conj_p.tamano() << endl;
	    }
	}
	else if (c == "nueva_sesion" or c == "ns") {
	    string id;
	    cin >> id;
	    Sesion s(id);
	    s.leer();
	    cout << '#' << c << ' ' << id << endl;
	    if (conj_s.existe(id)) cout << "error: la sesion ya existe" << endl;
	    else {
		conj_s.anadir(id, s);
		cout << conj_s.tamano() << endl;
	    }
	}
	else if (c == "nuevo_curso" or c == "nc") {
	    cout << '#' << c << endl;
	    int id = conj_c.tamano()+1;
	    Curso cur(id);
	    cur.leer();
	    if (conj_c.existe(id)) cout << "error: el curso ya existe" << endl;
	    else {
		cur.inizializar_iterador();
		while (not cur.end() and not cur.existe_interseccion()) {
		    string id_s;
		    cur.valor(id_s);
		    conj_s.apuntar(id_s);
		    conj_s.anadir_problemas_a_curso(cur);
		    cur.incrementar_iterador();
		}
		if (cur.existe_interseccion()) cout << "error: curso mal formado" << endl;
		else {
		    conj_c.anadir(cur);
		    cout << conj_c.tamano() << endl;
		}
	    }
	}
	else if (c == "alta_usuario" or c == "a") {
	    string nombre;
	    cin >> nombre;
	    cout << '#' << c << ' ' << nombre << endl;
	    if (conj_u.existe(nombre)) cout << "error: el usuario ya existe" << endl;
	    else {
		conj_u.anadir(nombre);
		cout << conj_u.numero_usuarios() << endl;
	    }
	}
	else if (c == "baja_usuario" or c == "b") {
	    string nombre;
	    cin >> nombre;
	    cout << '#' << c << ' ' << nombre << endl;
	    if (conj_u.existe(nombre)) {
		int id_c;
		if (conj_u.usuario_inscrito_a_curso(id_c)) conj_c.usuario_baja_curso(id_c);
		conj_u.borrar();
		cout << conj_u.numero_usuarios() << endl;
	    }
	    else cout << "error: el usuario no existe" << endl;
	}
	else if (c == "inscribir_curso" or c == "i") {
	    string nombre;
	    int id_c;
	    cin >> nombre >> id_c;
	    cout << '#' << c << ' ' << nombre << ' ' << id_c << endl;
	    if (not conj_u.existe(nombre)) cout << "error: el usuario no existe" << endl;
	    else if (not conj_c.existe(id_c)) cout << "error: el curso no existe" << endl;
	    else if (conj_u.usuario_inscrito_a_curso(id_c)) cout << "error: usuario inscrito en otro curso" << endl;
	    else {
		conj_u.inscribir_usuario_a_curso(id_c);
		conj_c.inscribir_usuario_a_curso();
		conj_c.curso_inizializar_iterador();
		while (not conj_c.curso_end()) {
		    string id_s;
		    conj_c.curso_sesion_iterador(id_s);
		    conj_s.sesion_problemas_enviables_usuario(conj_u, id_s);
		    conj_c.curso_incrementar_iterador();
		}
		cout << conj_c.usuarios_actuales_curso() << endl;
	    }
	}
	else if (c == "curso_usuario" or c == "cu") {
	    string nombre;
	    cin >> nombre;
	    cout << '#' << c << ' ' << nombre << endl;
	    if (not conj_u.existe(nombre)) cout << "error: el usuario no existe" << endl;
	    else {
		int id_c;
		if (conj_u.usuario_inscrito_a_curso(id_c)) cout << id_c << endl;
		else cout << 0 << endl;
	    }
	}
	else if (c == "sesion_problema" or c == "sp") {
	    int id_c;
	    string id_p, id_s;
	    cin >> id_c >> id_p;
	    cout << '#' << c << ' ' << id_c << ' ' << id_p << endl;
	    if (not conj_c.existe(id_c)) cout << "error: el curso no existe" << endl;
	    else if (not conj_p.existe(id_p)) cout << "error: el problema no existe" << endl;
	    else if (not conj_c.curso_contiene_problema(id_p, id_s)) cout << "error: el problema no pertenece al curso" << endl;
	    else cout << id_s << endl;
	}
	else if (c == "problemas_resueltos" or c == "pr") {
	    string nombre;
	    cin >> nombre;
	    cout << '#' << c << ' ' << nombre << endl;
	    if (not conj_u.existe(nombre)) cout << "error: el usuario no existe" << endl;
	    else conj_u.usuario_escribir_problemas_resueltos();
	}
	else if (c == "problemas_enviables" or c == "pe") {
	    string nombre;
	    cin >> nombre;
	    cout << '#' << c << ' ' << nombre << endl;
	    int id_c; //para la función usuario_inscrito_a_curso
	    if (not conj_u.existe(nombre)) cout << "error: el usuario no existe" << endl;
	    else if (not conj_u.usuario_inscrito_a_curso(id_c)) cout << "error: usuario no inscrito en ningun curso" << endl;
	    else conj_u.usuario_escribir_problemas_enviables();
	}
	else if (c == "envio" or c =="e") {
	    int r;
	    string nombre, id_p;
	    cin >> nombre >> id_p >> r;
	    cout << '#' << c << ' ' << nombre << ' ' << id_p << ' ' << r << endl;
	    conj_u.apuntar(nombre);
	    conj_u.usuario_envio_problema(id_p);
	    conj_p.apuntar(id_p);
	    conj_p.incrementar_envios_totales_problema();
	    if (r == 1) {
		conj_p.incrementar_envios_exitosos_problema();
		conj_u.usuario_problema_correcto(id_p);
		int id_c;
		conj_u.curso_usuario(id_c);
		conj_c.apuntar(id_c);
		string id_s;
		conj_c.curso_contiene_problema(id_p, id_s);
		conj_s.sesion_problemas_enviables_usuario(conj_u, id_s);
		if (conj_u.num_problemas_enviables_usuario() == 0) {
		    conj_u.usuario_finaliza_curso();
		    conj_c.usuario_finaliza_curso();
		}
	    }
	}
	else if (c == "listar_problemas" or c =="lp") {
	    cout << '#' << c << endl;
	    conj_p.listar();
	}
	else if (c == "escribir_problema" or c == "ep") {
	    string id;
	    cin >> id;
	    cout << '#' << c << ' ' << id << endl;
	    if (conj_p.existe(id)) conj_p.escribir_problema();
	    else cout << "error: el problema no existe" << endl;
	}
	else if (c == "listar_sesiones" or c == "ls") {
	    cout << '#' << c << endl;
	    conj_s.listar();
	}
	else if (c == "escribir_sesion" or c == "es") {
	    string id;
	    cin >> id;
	    cout << '#' << c << ' ' << id << endl;
	    if (conj_s.existe(id)) conj_s.escribir_sesion();
	    else cout << "error: la sesion no existe" << endl;
	}
	else if (c == "listar_cursos" or c == "lc") {
	    cout << '#' << c << endl;
	    conj_c.listar();
	}
	else if (c == "escribir_curso" or c == "ec") {
	    int id;
	    cin >> id;
	    cout << '#' << c << ' ' << id << endl;
	    if (conj_c.existe(id)) conj_c.escribir_curso();
	    else cout << "error: el curso no existe" << endl;
	}
	else if (c == "listar_usuarios" or c == "lu") {
	    cout << '#' << c << endl;
	    conj_u.listar();
	}
	else if (c == "escribir_usuario" or c == "eu") {
	    string nombre;
	    cin >> nombre;
	    cout << '#' << c << ' ' << nombre << endl;
	    if (conj_u.existe(nombre)) conj_u.escribir_usuario();
	    else cout << "error: el usuario no existe" << endl;
	}
	cin >> c;
    }
}
