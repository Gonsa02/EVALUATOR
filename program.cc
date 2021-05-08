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
	    Problema p;
	    p.leer();
	    string id;
	    p.obtener_id(id);
	    cout << '#' << c << ' ' << id << endl;
	    if (conj_p.existe(p)) cout << "error: el problema ya existe" << endl;
	    else {
		conj_p.anadir(p);
		cout << conj_p.tamano() << endl;
	    }
	}
	else if (c == "nueva_sesion" or c == "ns") {
	    Sesion s;
	    s.leer();
	    string id;
	    s.obtener_id(id);
	    cout << '#' << c << ' ' << id << endl;
	    if (conj_s.existe(s)) cout << "error: la sesion ya existe" << endl;
	    else {
		conj_s.anadir(s);
		cout << conj_s.tamano() << endl;
	    }
	}
	else if (c == "nuevo_curso" or c == "nc") {
	    cout << '#' << c << endl;
	    Curso cur;
	    cur.leer();
	    if (conj_c.existe(cur)) cout << "error: el curso ya existe" << endl;
	    else {
		cur.inizializar_iterador();
		while (not cur.end() and not cur.existe_interseccion()) {
		    string id_s;
		    cur.valor(id_s);
		    Sesion s;
		    conj_s.obtener_con_id(id_s, s);
		    s.anadir_problemas_a_curso(cur);
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
	    Usuario u;
	    u.leer();
	    string nombre;
	    u.obtener_nombre(nombre);
	    cout << '#' << c << ' ' << nombre << endl;
	    if (conj_u.existe(u)) cout << "error: el usuario ya existe" << endl;
	    else {
		conj_u.anadir(u);
		cout << conj_u.numero_usuarios() << endl;
	    }
	}
	else if (c == "baja_usuario" or c == "b") {
	    Usuario u;
	    u.leer();
	    string nombre;
	    u.obtener_nombre(nombre);
	    cout << '#' << c << ' ' << nombre << endl;
	    if (conj_u.existe(u)) {
		if (u.inscrito_a_curso()) conj_c.usuario_baja_curso(u.curso());
		conj_u.borrar(u);
		cout << conj_u.numero_usuarios() << endl;
	    }
	    else cout << "error: el usuario no existe" << endl;
	}
	else if (c == "inscribir_curso" or c == "i") {
	    Usuario u;
	    Curso cur;
	    u.leer();
	    string nombre;
	    u.obtener_nombre(nombre);
	    cout << '#' << c << ' ' << nombre << ' ' << cur.obtener_id() << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else if (not conj_c.existe(cur)) cout << "error: el curso no existe" << endl;
	    else if (u.inscrito_a_curso()) cout << "error: usuario inscrito en otro curso" << endl;
	    else {
		u.inscribir_a_curso(cur.obtener_id());
		cur.usuario_inscribir_curso();
		cur.inizializar_iterador();
		while (not cur.end()) {
		    string id_s;
		    cur.valor(id_s);
		    Sesion s;
		    conj_s.obtener_con_id(id_s, s);
		    s.problemas_enviables(u);
		    cur.incrementar_iterador();
		}
		conj_c.actualizar(cur);
		conj_u.actualizar(u);
		cout << cur.usuarios_actuales() << endl;
	    }
	}
	else if (c == "curso_usuario" or c == "cu") {
	    Usuario u;
	    u.leer();
	    string nombre;
	    u.obtener_nombre(nombre);
	    cout << '#' << c << ' ' << nombre << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else {
		if (u.inscrito_a_curso()) cout << u.curso() << endl;
		else cout << 0 << endl;
	    }
	}
	else if (c == "sesion_problema" or c == "sp") {
	    Curso cur;
	    Problema p;
	    cur.leer_id();
	    p.leer();
	    string id;
	    p.obtener_id(id);
	    cout << '#' << c << ' ' << cur.obtener_id() << ' ' << id << endl;
	    if (not conj_c.existe(cur)) cout << "error: el curso no existe" << endl;
	    else if (not conj_p.existe(p)) cout << "error: el problema no existe" << endl;
	    else if (not cur.contiene_problema(id)) cout << "error: el problema no pertenece al curso" << endl;
	    else {
		string id_s;
		cur.sesion_problema(id, id_s);
		cout << id_s << endl;
	    }
	}
	else if (c == "problemas_resueltos" or c == "pr") {
	    Usuario u;
	    u.leer();
	    string nombre;
	    u.obtener_nombre(nombre);
	    cout << '#' << c << ' ' << nombre << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else u.escribir_problemas_resueltos();
	}
	else if (c == "problemas_enviables" or c == "pe") {
	    Usuario u;
	    u.leer();
	    string nombre;
	    u.obtener_nombre(nombre);
	    cout << '#' << c << ' ' << nombre << endl;
	    if (not conj_u.existe(u)) cout << "error: el usuario no existe" << endl;
	    else if (not u.inscrito_a_curso()) cout << "error: usuario no inscrito en ningun curso" << endl;
	    else u.escribir_problemas_enviables();
	}
	else if (c == "envio" or c =="e") {
	    int r;
	    string nombre, id_problema;
	    cin >> nombre >> id_problema >> r;
	    cout << '#' << c << ' ' << nombre << ' ' << id_problema << ' ' << r << endl;
	    Usuario u;
	    conj_u.obtener(nombre, u);
	    u.anadir_intento_problema(id_problema);
	    Problema p;
	    conj_p.obtener(id_problema, p);
	    p.incrementar_envios_totales();
	    if (r == 1) {
		p.incrementar_envios_exitosos();
		u.anadir_problema_correcto(id_problema);
		Curso c;
		conj_c.obtener_con_id(u.curso(), c);
		Sesion s;
		string id_s;
		c.sesion_problema(id_problema, id_s);
		conj_s.obtener_con_id(id_s, s);
		s.problemas_envio(u, id_problema);
		if (u.num_problemas_enviables() == 0) {
		    u.finalizar_curso();
		    c.usuario_finaliza_curso();
		    conj_c.actualizar(c);	
		}
	    }
	    conj_u.actualizar(u);
	    conj_p.actualizar(p);
	}
	else if (c == "listar_problemas" or c =="lp") {
	    cout << '#' << c << endl;
	    conj_p.listar();
	}
	else if (c == "escribir_problema" or c == "ep") {
	    Problema p;
	    p.leer();
	    string id;
	    p.obtener_id(id);
	    cout << '#' << c << ' ' << id << endl;
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
	    string id;
	    s.obtener_id(id);
	    cout << '#' << c << ' ' << id << endl;
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
	    string nombre;
	    u.obtener_nombre(nombre);
	    cout << '#' << c << ' ' << nombre << endl;
	    if (conj_u.existe(u)) u.escribir_usuario();
	    else cout << "error: el usuario no existe" << endl;
	}
	cin >> c;
    }
}
