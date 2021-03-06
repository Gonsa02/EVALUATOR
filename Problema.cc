/** @file Problema.cc
    @brief Implementación de la clase Problema
*/

#include "Problema.hh"

Problema::Problema(const string& id)
{
    this -> id = id;
    env_exito = 0;
    env_totales = 0;
    ratio = 1;
}

void Problema::incrementar_envios_totales()
{
    env_totales++;
    actualizar_ratio();
};

void Problema::incrementar_envios_exitosos()
{
    env_exito++;
    actualizar_ratio();
};

void Problema::escribir_problema() const
{
    cout << id << '('<< env_totales << ',' << env_exito << "," << ratio << ')' << endl;
}

void Problema::leer()
{
    string id;
    cin >> id;
    this -> id = id;
}

void Problema::actualizar_ratio() 
{
    ratio = double(env_totales+1)/double(env_exito+1);
}

bool Problema::operator<(const Problema &p) const
{
    if (ratio != p.ratio) return ratio < p.ratio;
    else return id < p.id;
}
