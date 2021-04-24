#include "Operaciones_auxiliares.hh"

void dar_baja(Conjunto_Usuarios &conj_u, Conjunto_Cursos &conj_c, const Usuario &u)
{
    // Borramos el Usuario del Curso
    Curso c;
    conj_c.obtener_con_id(u.curso(), c);
    c.usuario_dar_baja_curso();
    conj_c.actualizar(c);
    
    // Eliminamos el Usuario del Conjunto_Usuarios
    conj_u.borrar(u);
}

void inscribir_usuario_a_curso(Conjunto_Usuarios &conj_u, Conjunto_Cursos &conj_c, Usuario &u, Curso &c)
{
    // Inscribimos al Usuario y lo registramos
    conj_u.obtener(u.obtener_nombre(), u);
    u.inscribir_a_curso(c.obtener_id());
    conj_u.actualizar(u);

    // Incrementamos en numero de usuarios del Curso
    conj_c.obtener_con_id(c.obtener_id(), c);
    c.usuario_inscribir_curso();
    conj_c.actualizar(c);
}

void envio(Conjunto_Usuarios &conj_u, Conjunto_Cursos &conj_c, Conjunto_Problemas &conj_p, string nombre, string id_problema, int r)
{
    Usuario u;
    conj_u.obtener(nombre, u);
    u.incrementar_envios_totales();
    Problema p;
    conj_p.obtener(id_problema, p);
    p.incrementar_envios_totales();
}
