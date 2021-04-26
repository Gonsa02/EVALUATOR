#include "Operaciones_auxiliares.hh"
#include "Conjunto_Sesiones.hh"

void dar_baja(Conjunto_Usuarios &conj_u, Conjunto_Cursos &conj_c, const Usuario &u)
{
    // Borramos el Usuario del Curso
    if (u.inscrito_a_curso()) {
	Curso c;
	conj_c.obtener_con_id(u.curso(), c);
	c.usuario_dar_baja_curso();
	conj_c.actualizar(c);
    }
    
    // Eliminamos el Usuario del Conjunto_Usuarios
    conj_u.borrar(u);
}

void inscribir_usuario_a_curso(Conjunto_Usuarios &conj_u, Conjunto_Cursos &conj_c, Conjunto_Sesiones &conj_s, Usuario &u, Curso &c)
{
    conj_c.obtener_con_id(c.obtener_id(), c);
    conj_u.obtener(u.obtener_nombre(), u);

    // Inscribimos al Usuario, le ponemos los problemas iniciales del Curso y lo registramos
    u.inscribir_a_curso(c.obtener_id());
    vector<string> v = c.problemas_iniciales(conj_s);
    for (int i = 0; i < v.size(); ++i) u.anadir_problema_enviable(v[i]);
    conj_u.actualizar(u);

    // Incrementamos en numero de usuarios del Curso
    c.usuario_inscribir_curso();
    conj_c.actualizar(c);
}

void envio(Conjunto_Usuarios &conj_u, Conjunto_Cursos &conj_c, Conjunto_Problemas &conj_p, Conjunto_Sesiones &conj_s, string nombre, string id_problema, int r)
{
    Usuario u;
    conj_u.obtener(nombre, u);
    u.incrementar_envios_totales();
    u.anadir_problema_intentado(id_problema);
    Problema p;
    conj_p.obtener(id_problema, p);
    p.incrementar_envios_totales();
    if (not u.problema_intentado(id_problema)) u.anadir_problema_intentado(id_problema);
    if (r == 1) {
	// Acutalizamos el Problema
	p.incrementar_envios_exitosos();

	// Actualizamos el Usuario
	u.anadir_problema_correcto(id_problema);
	u.quitar_problema_enviable(id_problema);
	Curso c;
	conj_c.obtener_con_id(u.curso(), c);
	string id_sesion = c.sesion_problema(id_problema, conj_s);
	Sesion s;
	conj_s.obtener_con_id(id_sesion, s);
	vector<string> v = s.problemas_sucesores(id_problema);
	for (int i = 0; i < v.size(); ++i) u.anadir_problema_enviable(v[i]);
	if (u.num_problemas_enviables() == 0) {
	    u.finalizar_curso();
	    c.usuario_finaliza_curso();
	}
	conj_c.actualizar(c);
    }
    conj_u.actualizar(u);
    conj_p.actualizar(p);
}
