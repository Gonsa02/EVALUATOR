#include "Problema.hh"

Problema::Problema(string ID) 
{
    id = ID;
    env_exito = 0;
    env_totales = 0;
    ratio = 0;
}

Problema::~Problema(){}

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

string Problema::obtener_id() const
{
    return id;
}

int Problema::envios_totales() const
{
    return env_totales;
}

double Problema::obtener_ratio() const
{
    return ratio;
}

void Problema::escribir_problema() const
{
    cout << env_totales << " " << env_exito << " " << ratio << endl;
}

void Problema::actualizar_ratio() 
{
    ratio = double(env_totales+1)/double(env_exito+1);
}
