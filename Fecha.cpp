#include <iostream>
#include <iomanip>
#include "Fecha.h"

Fecha::Fecha(){
    dia = 14;
    mes = 5;
    annio = 2022;
}

Fecha::Fecha(int _dia, int _mes, int _annio){
    dia = _dia;
    mes = _mes;
    annio = _annio;
}

Fecha::~Fecha(){}

int Fecha::getDia() const{
    return dia;
}

int Fecha::getMes() const{
    return mes;
}

int Fecha::getAnnio() const{
    return annio;
}

void Fecha::setDia(int _dia){
    dia = _dia;
}

void Fecha::setMes(int _mes){
    mes = _mes;
}

void Fecha::setAnnio(int _annio){
    annio = _annio;
}

void Fecha::imprimeFecha(){
    std::cout << "Fecha: ";
    std::cout.fill('0');
    std::cout << std::setw(2) << dia << "/" << std::setw(2) << mes << "/" << annio;
}