#include "Ficha.h"
#include <iostream>
using namespace std;

Ficha::Ficha(){
this->rol="";
this->rut="";
this->nombre="";
this->direccion="";
this->afp="";
this->salud="";
this->seguros="";
this->bonos="";
this->gratificaciones="";
this->prestamos="";
this->sueldo_base="";
}

Ficha::Ficha (string _rol, string _rut, string _nombre, string _direccion, string _afp, string _salud, string _seguros, string _bonos, string _gratificaciones, string _prestamos, string _sueldoBase ){
this->rol=_rol;
this->rut=_rut;
this->nombre=_nombre;
this->direccion=_direccion;
this->afp=_afp;
this->salud=_salud;
this->seguros=_seguros;
this->bonos=_bonos;
this->gratificaciones=_gratificaciones;
this->prestamos=_prestamos;
this->sueldo_base=_sueldoBase;
}

/*Patente::~Patente(){
    cout<<"Se destruyo"<<endl;
}*/

void Ficha::setRol(string value) {
    this->rol = value;
}

void Ficha::setNombre(string value) {
    this->nombre = value;
}

void Ficha::setRut(string value) {
    this->rut = value;
}

void Ficha::setDireccion(string value) {
    this->direccion = value;
}

void Ficha::setAfp(string value) {
    this->afp = value;
}

void Ficha::setSalud(string value) {
    this->salud = value;
}

void Ficha::setSeguros(string value) {
    this->seguros = value;
}

void Ficha::setBonos(string value) {
    this->bonos = value;
}

void Ficha::setGratificaciones(string value) {
    this->gratificaciones = value;
}

void Ficha::setPrestamos(string value) {
    this->prestamos = value;
}

void Ficha::setSueldo_Base(string value) {
    this->sueldo_base = value;
}

// Getters
string Ficha::getRol() {
    return this->rol;
}

string Ficha::getNombre() {
    return this->nombre;
}

string Ficha::getRut() {
    return this->rut;
}

string Ficha::getDireccion() {
    return this->direccion;
}

string Ficha::getAfp() {
    return this->afp;
}

string Ficha::getSalud() {
    return this->salud;
}

string Ficha::getSeguros() {
    return this->seguros;
}

string Ficha::getBonos() {
    return this->bonos;
}

string Ficha::getGratificaciones() {
    return this->gratificaciones;
}

string Ficha::getPrestamos() {
    return this->prestamos;
}

string Ficha::getSueldo_Base() {
    return this->sueldo_base;
}

// Función miembro
void Ficha::ver() {
    cout << "Rol: " << rol << endl;
    cout << "Rut: " << rut << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "AFP: " << afp << endl;
    cout << "Salud: " << salud << endl;
    cout << "Seguros: " << seguros << endl;
    cout << "Bonos: " << bonos << endl;
    cout << "Gratificaciones: " << gratificaciones << endl;
    cout << "Prestamos: " << prestamos << endl;
    cout << "Sueldo Base: " << sueldo_base << endl;
}