#include "Pasajero.h"

Pasajero::Pasajero(){
    nombre = "David";
    telefono = "4444304686";
    puntosKm = 0;
    vuelo = 0;
}

Pasajero::Pasajero(std::string _nombre, std::string _telefono, int _puntosKm, int _vuelo){
    nombre = _nombre;
    telefono = _telefono;
    puntosKm = _puntosKm;
    vuelo = _vuelo;
}

Pasajero::~Pasajero(){}

std::string Pasajero::getNombre() const{
    return nombre;
}

std::string Pasajero::getTelefono() const{
    return telefono;
}

int Pasajero::getPuntosKm() const{
    return puntosKm;
}

int Pasajero::getVuelo() const{
    return vuelo;
}

void Pasajero::setNombre(std::string _nombre){
    nombre = _nombre;
}

void Pasajero::setTelefono(std::string _telefono){
    telefono = _telefono;
}

void Pasajero::setPuntosKm(int _puntosKm){
    puntosKm = _puntosKm;
}

void Pasajero::setVuelo(int _vuelo){
    vuelo = _vuelo;
}

void Pasajero::imprimePasajero(){
    std::cout << std::endl << nombre << std::endl;
    std::cout << "Telefono: " << telefono << std::endl;
    std::cout << "Puntos: " << puntosKm << std::endl;
}