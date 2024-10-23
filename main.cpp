#include <fstream>
#include "Vuelo.h"
#include "Pasajero.h"
#include "Usuario.h"
using namespace std;

void InfoVuelos(vector<Vuelo> &infVuelos){
    int tamVuelo_, dia_, mes_, annio_, numVuelo_, precio_, distancia_, hh_, mm_;
    string destino_, aerolinea_;
    ifstream archivo;
    archivo.open("Vuelos.txt");
    while(archivo >> tamVuelo_ >> dia_ >> mes_ >> annio_ >> numVuelo_ >> destino_ >> precio_ >> distancia_ >> aerolinea_ >> hh_ >> mm_){ 
        Fecha nuevaF(dia_, mes_, annio_);
        Hora nuevaH(hh_, mm_);
        Vuelo nuevoV(tamVuelo_, nuevaF, numVuelo_, destino_, precio_, distancia_, aerolinea_, nuevaH);
        infVuelos.push_back(nuevoV);
    }
    archivo.close();
}

void ImprimeVuelos(vector<Vuelo> infVuelos){
    for(int pos=0; pos<infVuelos.size(); pos++){
        cout << "Vuelo #" << pos+1 << endl;
        infVuelos[pos].imprimeVuelo();
    }
}

void AgregarPasajeroManual(vector<Pasajero> &infPasajero, vector<Vuelo> &infVuelos){
    string nombre_, telefono_;
    int puntosKm_, numVuelo;
    cout << "Ingresa el nombre: ";
    cin >> nombre_;
    cout << "Ingresa el telefono: ";
    cin >> telefono_;
    cout << "Ingresa los puntos acumulados: ";
    cin >> puntosKm_;
    cout << "A que vuelo deseas agregarlo?: ";
    cin >> numVuelo;
    if(puntosKm_ >= 5000){
        int resp;
        cout << "Quiere utilizar 5000 puntos para obtener un 40 por ciento de descuento? (1.Si 2.No): ";
        cin >> resp;
        if(resp == 1){
            puntosKm_ -= 5000;
            cout << "Puntos restantes = " << puntosKm_ << endl;
        }
    }
    for(int pos=0; pos<infVuelos.size(); pos++){
        if(infVuelos[pos].getNumVuelo() == numVuelo){
            puntosKm_ += infVuelos[pos].getDistancia();
        }
    }
    Pasajero nuevoP(nombre_, telefono_, puntosKm_, numVuelo);
    infPasajero.push_back(nuevoP);
}

void AgregarPasajerosArchivo(vector<Pasajero> &infPasajero){
    string nombre_, telefono_;
    int puntosKm_, numVuelo;
    cout << "A que vuelo deseas agregarlo?: ";
    cin >> numVuelo;
    ifstream archivo;
    archivo.open("pasajeros.txt");
    while(archivo >> nombre_ >> telefono_ >> puntosKm_){
        Pasajero nuevoP(nombre_, telefono_, puntosKm_, numVuelo);
        infPasajero.push_back(nuevoP);
    }
}

void ImprimirPasajeros(vector<Pasajero> infPasajero){
    int v;
    cout << "Ingrese el numero de vuelo del que desea los pasajeros: ";
    cin >> v;
    for(int pos=0; pos<infPasajero.size(); pos++){
        if(infPasajero[pos].getVuelo() == v){
            infPasajero[pos].imprimePasajero(); 
        }
    }
}

void BorrarPasajero(vector<Pasajero> &infPasajero){
    string nom;
    cout << "Ingresa el nombre del pasajero que quieres eliminar: ";
    cin >> nom;
    for(int pos=0; pos<infPasajero.size(); pos++){
        if(infPasajero[pos].getNombre() == nom){
            infPasajero.erase(infPasajero.begin()+(pos));
        }
    }
}

void BuscarAerolinea(vector<Vuelo> &infVuelos){
    string nom;
    int rst = 0;
    cout << "Ingresa la aerolinea que deseas: ";
    cin >> nom;
    for(int pos=0; pos<infVuelos.size(); pos++){
        if(infVuelos[pos].getAerolinea() == nom){
            infVuelos[pos].imprimeVuelo();
            rst = 1;
        }
    }
    if(rst == 0){
        cout << "Sin resultados" << endl;
    }
}

void BuscarDestino(vector<Vuelo> &infVuelos){
    string nom;
    int rst = 0;
    cout << "Ingresa el destino que deseas: ";
    cin >> nom;
    for(int pos=0; pos<infVuelos.size(); pos++){
        if(infVuelos[pos].getDestino() == nom){
            infVuelos[pos].imprimeVuelo();
            rst = 1;
        }
    }
    if(rst == 0){
        cout << "Sin resultados" << endl;
    }
}

void Menu(){
    vector<Vuelo> vuelos;
    vector<Pasajero> pasajeros;
    char opc;
    do{
        system("cls");
        cout << "MENU" << endl; 
        cout<<"\t1.Imprimir todos los vuelos\n\t2.Agregar un Pasajero Manual\n\t3.Agregar Pasajeros con Archivo de Texto\n";
        cout << "\t4.Imprimir Pasajeros\n\t5.Borrar Pasajero\n\t6.Buscar Vuelo por Aerolinea\n\t7.Buscar Vuelo por Destino\n\t8.Salir\n"<<endl;
        cout << "Ingresa la opcion deseada: ";
        cin >> opc;
        switch (opc){
            case '1':{
                InfoVuelos(vuelos);
                ImprimeVuelos(vuelos);
                break;
            }
            case '2':{
                AgregarPasajeroManual(pasajeros, vuelos);
                break;
            }
            case '3':{
                AgregarPasajerosArchivo(pasajeros);
                break;
            }
            case '4':{
                ImprimirPasajeros(pasajeros);
                break;
            }
            case '5':{
                BorrarPasajero(pasajeros);
                break;
            }
            case '6':{
                BuscarAerolinea(vuelos);
                break;
            }
            case '7':{
                BuscarDestino(vuelos);
                break;
            }


        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Presiona enter para continuar...";
        cin.get();
    }while(opc != '8');
}

int InicarSesion(vector<Usuario> iniciar){
    int log = 0;
    string usuario, pswd;
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Password: ";
    cin >> pswd;
    while(log == 0){
        for(int i = 0; i < iniciar.size(); i++){
            if(iniciar[i].getUser() == usuario && iniciar[i].getPassword() == pswd){
                cout << "Bienvenido" << endl;
                Menu();
                log = 1;
                return 1;
            }
        }
        cout << "Usuario y/o password incorrectos" << endl;
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Password: ";
        cin >> pswd;
    }
    return 0;
}

void Registrar(vector<Usuario> &iniciar){
    string usuario, pwsd;
    cout << "Crea un usuario: ";
    cin >> usuario;
    cout << "Crea tu password: ";
    cin >> pwsd;
    Usuario nuevo(usuario, pwsd);
    iniciar.push_back(nuevo);
    cout << "Registro exitoso" << endl;
}

int main(){
    vector<Usuario> cuenta;
    Usuario prueba("Admin","1234");
    cuenta.push_back(prueba);
    int pety;
    int fun = 0;
    cout << "1.Iniciar Sesion" << endl;
    cout << "2.Crear Cuenta" << endl;
    cout << "3.Salir" << endl;
    cout << "Ingresa tu respuesta: ";
    cin >> pety;
    while(fun == 0){
        if(pety == 1){
            InicarSesion(cuenta);
        }
        else if(pety == 2){
            Registrar(cuenta);
        }else if(pety == 3){
            return 0;
        }else{
            cout << "Opcion incorrecta" << endl;
        }
        cout << "1.Iniciar Sesion" << endl;
        cout << "2.Crear Cuenta" << endl;
        cout << "3.Salir" << endl;
        cout << "Ingresa tu respuesta: ";
        cin >> pety;
    }
    return 0;
}