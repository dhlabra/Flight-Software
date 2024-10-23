#ifndef VUELO_H
#define VUELO_H
#include <vector>
#include "Fecha.h"
#include "Hora.h"

class Vuelo{
    public:
        Vuelo(int, Fecha, int, std::string, int, int, std::string, Hora);
        Vuelo();
        ~Vuelo();
        int getTamVuelo() const;
        Fecha getFechaVuelo() const;
        int getNumVuelo() const;
        std::string getDestino() const;
        int getPrecio() const;
        int getDistancia() const;
        std::string getAerolinea() const;
        Hora getHoraVuelo() const;
        void setTamVuelo(int);
        void setFechaVuelo(Fecha);
        void setNumVuelo(int);
        void setDestino(std::string);
        void setPrecio(int);
        void setDistancia(int);
        void setAerolinea(std::string);
        void setHoraVuelo(Hora);
        void imprimeVuelo();

    private:
        int tamVuelo;
        Fecha fechaVuelo;
        int numVuelo;
        std::string destino;
        int precio;
        int distancia;
        std::string aerolinea;
        Hora horaVuelo;
};

#endif// VUELO_H