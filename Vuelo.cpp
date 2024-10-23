#include <iostream>
#include "Vuelo.h"

Vuelo::Vuelo(){
    tamVuelo = 50;
    numVuelo = 2165;
    destino = "Cancun";
    precio = 1500;
    distancia = 200;
    aerolinea = "Aeromexico";
}

Vuelo::Vuelo(int _tamVuelo, Fecha _fechaVuelo, int _numVuelo, std::string _destino, int _precio, int _distancia, std::string _aerolinea, Hora _horaVuelo){
    tamVuelo = _tamVuelo;
    fechaVuelo = _fechaVuelo;
    numVuelo = _numVuelo;
    destino = _destino;
    precio = _precio;
    distancia = _distancia;
    aerolinea = _aerolinea;
    horaVuelo = _horaVuelo;
}

Vuelo::~Vuelo(){}

int Vuelo::getTamVuelo() const{
    return tamVuelo;
}

int Vuelo::getNumVuelo() const{
    return numVuelo;
}

std::string Vuelo::getDestino() const{
    return destino;
}

int Vuelo::getPrecio() const{
    return precio;
}

int Vuelo::getDistancia() const{
    return distancia;
}

std::string Vuelo::getAerolinea() const{
    return aerolinea;
}

void Vuelo::setTamVuelo(int _tamVuelo){
    tamVuelo = _tamVuelo;
}

void Vuelo::setNumVuelo(int _numVuelo){
    numVuelo = _numVuelo;
}

void Vuelo::setDestino(std::string _destino){
    destino = _destino;
}

void Vuelo::setPrecio(int _precio){
    precio = _precio;
}

void Vuelo::setDistancia(int _distancia){
    distancia = _distancia;
}

void Vuelo::setAerolinea(std::string _aerolinea){
    aerolinea = _aerolinea;
}

void Vuelo::imprimeVuelo(){
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Destino: " << destino << std::endl;
    std::cout << "Aerolinea: " << aerolinea << std::endl;
    std::cout << "No. de Vuelo: " << numVuelo << std::endl;
    std::cout << "Distancia: " << distancia << " km." << std::endl;
    std::cout << "Precio: $" << precio << std::endl;
    horaVuelo.imprimeHora();
    fechaVuelo.imprimeFecha();
    std::cout << std::endl << "-------------------------------------" << std::endl;
}