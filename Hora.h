#ifndef HORA_H
#define HORA_H

class Hora{
    public:
        Hora();
        Hora(int, int);
        ~Hora();
        int getHH() const;
        int getMM() const;
        void setHH(int);
        void setMM(int);
        void imprimeHora();

    private:
        int hh;
        int mm;

};

#endif// HORA_H