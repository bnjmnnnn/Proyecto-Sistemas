#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
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
// Función para dividir una cadena por un delimitador
vector<string> split(const string& lineaASeparar, char delimitador) { 
    vector<string> vector_interno;
    stringstream linea(lineaASeparar);
    string parteDelString;

    while (getline(linea, parteDelString, delimitador)) {
        vector_interno.push_back(parteDelString);
    }
    return vector_interno;
}

// Función para leer datos desde un archivo y almacenarlos en un array de objetos Ficha
void leer_Archivo(const string& nombreArchivo, Ficha vFichas[], int& indice) {
    ifstream archivo(nombreArchivo);
    string lineaObtenida;

    if (archivo.is_open()) {
        while (getline(archivo, lineaObtenida, '\n')) {
            vector<string> data = split(lineaObtenida, ';');
            Ficha p(data[POS_ROL], data[POS_RUT], data[POS_NOMBRE], data[POS_DIRECCION], 
                     data[POS_AFP], data[POS_SALUD], data[POS_SEGUROS], data[POS_BONOS], 
                     data[POS_GRATIFICACIONES], data[POS_PRESTAMOS], data[POS_SUELDO_BASE]);
            vFichas[indice] = p;
            indice++;
        }
        archivo.close();
    }
}

bool esNumeroValido(const string& cadena) {
    // Verifica si la cadena está vacía
    if (cadena.empty()) return false;
    
    char* end;
    std::strtod(cadena.c_str(), &end);
    
    // Verifica si toda la cadena se convirtió a número
    return (*end == '\0');
}
void Totalizar_Descuentos(Ficha misFichas[], int n, const map<string, double>& afpPorcentajes, const map<string, double>& saludPorcentajes) {
    for (int i = 0; i < n; i++) {
        // Convertir sueldo base de string a int
        int sueldoBase = atoi(misFichas[i].getSueldo_Base().c_str());

        // Obtener porcentaje de AFP
        double porcentajeAFP = 0.0;
        auto itAFP = afpPorcentajes.find(misFichas[i].getAfp());
        if (itAFP != afpPorcentajes.end()) {
            porcentajeAFP = itAFP->second;
        } else {
            cout << "Porcentaje de AFP no encontrado para el empleado con RUT: " << misFichas[i].getRut() << endl;
            continue; // Si no se encuentra el porcentaje, se omite este empleado
        }

        // Obtener porcentaje de salud
        double porcentajeSalud = 0;
        auto itSalud = saludPorcentajes.find(misFichas[i].getSalud());
        if (itSalud != saludPorcentajes.end()) {
            porcentajeSalud = itSalud->second;
        } else {
            cout << "Porcentaje de salud no encontrado para el empleado con RUT: " << misFichas[i].getRut() << endl;
            continue; // Si no se encuentra el porcentaje, se omite este empleado
        }

        // Calcular descuentos
        int descuentoSalud = sueldoBase * porcentajeSalud;
        int descuentoAFP = sueldoBase * porcentajeAFP;
        int descuentoSeguros = atoi(misFichas[i].getSeguros().c_str()); // Si `getSeguros` devuelve el monto total del seguro

        // Total de descuentos para el empleado
        int descuentoTotal = descuentoAFP + descuentoSalud + descuentoSeguros;

        // Mostrar el descuento total para el empleado
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "Descuento total para el empleado con RUT: " << misFichas[i].getRut() << endl;
        cout << "Descuento AFP: $" << descuentoAFP << endl;
        cout << "Descuento Salud: $" << descuentoSalud << endl;
        cout << "Descuento Seguros: $" << descuentoSeguros << endl;
        cout << "Descuento Total: $" << descuentoTotal << endl;
        cout << "---------------------------------------------------------------------------" << endl;
    }
}







int main() {
    int indice = 0;
    
    map<string, double> afpPorcentajes = {
        {"Provida", 0.1},  // 10%
        {"Capital", 0.12},    // 12%
        {"AFP3", 0.08}     // 8%
    };
    map<string, double> saludPorcentajes = {
        {"FonasaA", 0.07}, // 7%
        {"Isapre", 0.08}    // 8%
    };

    string archivo = "datos_trabajadores.txt";
    Ficha misFichas[MAX_ARRAY];
    leer_Archivo(archivo, misFichas, indice);
    cout << "[Cantidad registros leídos: " << indice << "]" << endl;
    Totalizar_Descuentos(misFichas, indice, afpPorcentajes, saludPorcentajes);
    cout << "Valor de salud para el empleado con RUT " << misFichas[1].getRut() << ": " << misFichas[1].getSalud() << endl;

    return 0;
}
