#ifndef FICHA_H
#define FICHA_H

#include <iostream>
using namespace std;

class Ficha{
    private:
    //atributos
        string rol;
        string nombre;
        string rut;
        string direccion;
        string afp;
        string salud;
        string seguros;
        string bonos;
        string gratificaciones;
        string prestamos;
        string sueldo_base;
    public:
    //constructor
        Ficha();
        Ficha(string, string, string, string, string, string, string, string, string, string, string);
    //Destructor
        //~Patente();
    //setters
        void setRol(string);
        void setNombre(string);
        void setRut(string);
        void setDireccion(string);
        void setAfp(string);
        void setSalud(string);
        void setSeguros(string);
        void setBonos(string);
        void setGratificaciones(string);
        void setPrestamos(string);
        void setSueldo_Base(string);
    //getters
        string getRol();
        string getNombre();
        string getRut();
        string getDireccion();
        string getAfp();
        string getSalud();
        string getSeguros();
        string getBonos();
        string getGratificaciones();
        string getPrestamos();
        string getSueldo_Base();
    //funcion miembro
        void ver();
};
#endif      