#ifndef FECHA_H
#define FECHA_H

class Fecha{
    public:
        Fecha();
        Fecha(int, int, int);
        ~Fecha();
        int getDia() const;
        int getMes() const;
        int getAnnio() const;
        void setDia(int);
        void setMes(int);
        void setAnnio(int);
        void imprimeFecha();

    private:
        int dia;
        int mes;
        int annio;
};

#endif// FECHA_H