#include "aed2_Servidor.h"
#include "SimCity.h"
// Completar

void aed2_Servidor::avanzarTurno(Jugador j) {
    //Revisar si es posible mandarles un jugador que no este registrado en las partidas
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return;
    }
    element->second.avanzarTurno();
}

void aed2_Servidor::agregarComercio(Jugador j, Casilla c) {
    //Revisar si es posible mandarles un jugador que no este registrado en las partidas
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return;
    }
    element->second.agregarComercio(c);
}

void aed2_Servidor::agregarCasa(Jugador j, Casilla c) {
    //Revisar si es posible mandarles un jugador que no este registrado en las partidas
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return;
    }
    element->second.agregarCasa(c);
}

void aed2_Servidor::nuevaPartida(Jugador j, set<int> horizontales, set<int> verticales) {
    Mapa mapa = make_pair(horizontales,verticales);
    Partidas.insert({j, SimCity(mapa)});
}

aed2_Servidor::aed2_Servidor() {

}

void aed2_Servidor::unir(Jugador j1, Jugador j2) {

}

set<int> aed2_Servidor::riosHorizontales(Jugador j) const {
    //Revisar si es posible mandarles un jugador que no este registrado en las partidas
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return set<int>();
    }
    return element->second.riosHorizontales();
}

set<int> aed2_Servidor::riosVerticales(Jugador j) const {
    //Revisar si es posible mandarles un jugador que no este registrado en las partidas
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return set<int>();
    }
    return element->second.riosVerticales();
}

set<Casilla> aed2_Servidor::casas(Jugador j) const {
    //Revisar si es posible mandarles un jugador que no este registrado en las partidas
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return set<Casilla>();
    }

    return element->second.casas();
}

set<Casilla> aed2_Servidor::comercios(Jugador j) const {
    //Revisar si es posible mandarles un jugador que no este registrado en las partidas
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return set<Casilla>();
    }
    return element->second.comercios();
}

Nat aed2_Servidor::nivel(Jugador j, Casilla c) const {
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return 0;
    }
    return element->second.nivel(c);
}

bool aed2_Servidor::huboConstruccion(Jugador j) const {
    return false;
}

Nat aed2_Servidor::popularidad(Jugador j) const {
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return 0;
    }
    return element->second.popularidad();
}

Nat aed2_Servidor::antiguedad(Jugador j) const {
    auto element = Partidas.find(j);
    if(element == Partidas.end()){
        return 0;
    }
    return element->second.antiguedad();
}
