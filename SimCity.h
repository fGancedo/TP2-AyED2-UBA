//
// Created by Thomas on 12/06/2022.
//
#include "Tipos.h"

#ifndef TP_SIMCITY_SIMCITY_H
#define TP_SIMCITY_SIMCITY_H


class SimCity {
public:
    SimCity(Mapa mapa);

    void avanzarTurno();

    void agregarCasa(Casilla c);

    void agregarComercio(Casilla c);

    set<int>  riosHorizontales() const;

    set<int> riosVerticales() const;

    set<Casilla> casas() const;

    set<Casilla> comercios() const;

    Nat nivel(Casilla c) const;

    Nat popularidad() const;

    Nat antiguedad() const;

private:
    std::map<Casilla,int> Casas;
    std::map<Casilla,int> Comercios;
    int Popularidad;
    Mapa MapaPartida;
    int Turnos;
    std::list<Casilla> CasasParaConstruir;
    std::list<Casilla> ComerciosParaConstruir;

};


#endif //TP_SIMCITY_SIMCITY_H
