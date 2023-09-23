//
// Created by Thomas on 12/06/2022.
//

#include "SimCity.h"

SimCity::SimCity(Mapa mapa) {
    Popularidad = 0;
    Turnos = 0;
    MapaPartida = mapa;
}

void SimCity::avanzarTurno() {

}

set<int> SimCity::riosHorizontales() const {
    return MapaPartida.first;
}

set<int> SimCity::riosVerticales() const {
    return MapaPartida.second;
}

set<Casilla> SimCity::casas() const {
    //Casas tiene que ser O(1)?
    std::set<Casilla> vints;
    for(auto const& imap: Casas)
        vints.insert(imap.first);
    return vints;
}

Nat SimCity::nivel(Casilla c) const {
    auto element = Casas.find(c);
    if(element != Casas.end()){
        return element->second;
    }

    element = Comercios.find(c);
    if(element != Comercios.end()){
        return element->second;
    }

    return 0;
}

Nat SimCity::popularidad() const {
    return Popularidad;
}

Nat SimCity::antiguedad() const {
    return Turnos;
}

set<Casilla> SimCity::comercios() const {
    std::set<Casilla> vints;
    for(auto const& imap: Comercios)
        vints.insert(imap.first);
    return vints;
}

void SimCity::agregarCasa(Casilla c) {
    //Consulta, no se debe agregar casas con respecto a los rios o se verifica en avanzar turno-
    CasasParaConstruir.push_back(c);
}

void SimCity::agregarComercio(Casilla c) {
    CasasParaConstruir.push_back(c);
}
