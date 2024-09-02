#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include <iomanip>
#include "Ficha.h"
#define POS_ROL 0
#define POS_RUT 1
#define POS_NOMBRE 2
#define POS_DIRECCION 3 
#define POS_AFP 4
#define POS_SALUD 5
#define POS_SEGUROS 6
#define POS_BONOS 7
#define POS_GRATIFICACIONES 8 
#define POS_PRESTAMOS 9
#define POS_SUELDO_BASE 10
#define MAX_ARRAY 798
using namespace std;

double calcularDescuentoAFP(double totalImponible, const string& afp);

vector<string> split(const string& lineaASeparar, char delimitador) { 
    vector<string> vector_interno;
    stringstream linea(lineaASeparar);
    string parteDelString;

    while (getline(linea, parteDelString, delimitador)) {
        vector_interno.push_back(parteDelString);
    }
    return vector_interno;
}

void leer_Archivo(const string& nombreArchivo, Ficha vFichas[], int& indice) {
    ifstream archivo(nombreArchivo);
    string lineaObtenida;

    if (archivo.is_open()) {
        while (getline(archivo, lineaObtenida, '\n')) {
            vector<string> data = split(lineaObtenida, ';');
            Ficha p(data[POS_ROL], data[POS_RUT], data[POS_NOMBRE], data[POS_DIRECCION], data[POS_AFP], data[POS_SALUD], data[POS_SEGUROS], data[POS_BONOS], 
                    data[POS_GRATIFICACIONES], data[POS_PRESTAMOS], data[POS_SUELDO_BASE]);
            vFichas[indice] = p;
            indice++;
        }
        archivo.close();
    }
}

void ActualizarSueldoBase(Ficha misFichas[], int n) {
    for (int i = 0; i < n; i++) {
        double sueldoBase = atof(misFichas[i].getSueldo_Base().c_str());
        double bonos = atof(misFichas[i].getBonos().c_str());
        double gratificaciones = atof(misFichas[i].getGratificaciones().c_str());
        double totalImponible = sueldoBase + bonos + gratificaciones;
        
        cout << "Nombre: " << misFichas[i].getNombre()<< " Sueldo base actualizado es: $" << totalImponible << endl;
        
        double descuentoAFP = calcularDescuentoAFP(totalImponible, misFichas[i].getAfp());
        cout << "Descuento AFP para la AFP " << misFichas[i].getAfp() << " es: $" << descuentoAFP << endl;
    }
}

// Función para calcular el descuento de AFP
double calcularDescuentoAFP(double totalImponible, const string& afp) {
    map<string, double> afpPorcentajes = {
        {"Provida", 0.1045},
        {"Capital", 0.1038},
        {"Hábitat", 0.1027},
        {"Cuprum", 0.1044},
        {"PlanVital", 0.1016},
        {"Modelo", 0.1027},
        {"UNO", 0.1034}
    };
    if (afpPorcentajes.find(afp) != afpPorcentajes.end()) {
        double porcentajeAFP = afpPorcentajes[afp];
        return totalImponible * porcentajeAFP;
    } else {
        // Si la AFP no está en el mapa, retorna 0 y muestra un mensaje de error
        cout << "Porcentaje de AFP no encontrado para la AFP: " << afp << endl;
        return 0.0;
    }
}

int main() {
    int indice = 0;
    string archivo = "datos_trabajadores.txt";
    Ficha misFichas[MAX_ARRAY];
    leer_Archivo(archivo, misFichas, indice);
    cout << "[Cantidad registros leídos: " << indice << "]" << endl;
    ActualizarSueldoBase(misFichas, indice);

    return 0;
}
