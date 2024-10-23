#include <iostream>
#include <iomanip>
#include "Hora.h"

Hora::Hora(){
    hh = 10;
    mm = 0;
}

Hora::Hora(int _hh, int _mm){
    hh = _hh;
    mm = _mm;
}

Hora::~Hora(){}

int Hora::getHH() const{
    return hh;
}

int Hora::getMM() const{
    return mm;
}

void Hora::setHH(int _hh){
    hh = _hh;
}

void Hora::setMM(int _mm){
    mm = _mm;
}

void Hora::imprimeHora(){
    std::cout << "Hora de partida: ";
    std::cout.fill('0');
    std::cout << std::setw(2) << hh << ":" << std::setw(2) << mm << std::endl;
}