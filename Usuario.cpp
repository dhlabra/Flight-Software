#include "Usuario.h"

Usuario::Usuario(){
    user = "test1";
    password = "password1";
}

Usuario::Usuario(std::string _user, std::string _password){
    user = _user;
    password = _password;
}

Usuario::~Usuario(){}

std::string Usuario::getUser() const{
    return user;
}

std::string Usuario::getPassword() const{
    return password;
}

void Usuario::setUser(std::string _user){
    user = _user;
}

void Usuario::setPassword(std::string _password){
    password = _password;
}

void Usuario::imprimeUsuario(){
    std::cout << user << std::endl << password << std::endl;
}
