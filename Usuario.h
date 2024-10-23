#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

class Usuario{
    public:
        Usuario();
        Usuario(std::string, std::string);
        ~Usuario();
        std::string getUser() const;
        std::string getPassword() const;
        void setUser(std::string);
        void setPassword(std::string);
        void imprimeUsuario();

    private:
        std::string user;
        std::string password;

};

#endif// USUARIO_H