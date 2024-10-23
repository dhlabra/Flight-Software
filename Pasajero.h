#ifndef PASAJERO_H
#define PASAJERO_H
#include <iostream>

class Pasajero{
    public:
        Pasajero();
        Pasajero(std::string, std::string, int, int);
        ~Pasajero();
        std::string getNombre() const;
        std::string getTelefono() const;
        int getPuntosKm() const;
        int getVuelo() const;
        void setNombre(std::string);
        void setTelefono(std::string);
        void setPuntosKm(int);
        void setVuelo(int);
        void imprimePasajero();

    private:
        std::string nombre;
        std::string telefono;
        int puntosKm;
        int vuelo;
};

#endif// PASAJERO_H