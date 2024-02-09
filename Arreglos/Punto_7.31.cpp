#include <iostream>
#include <string>

using namespace std;

int calcularFrecuencia(const string arreglo[], int longitud, const string& cadenaBuscada) {
    int frecuencia = 0;

    for (int i = 0; i < longitud; ++i) {
        if (arreglo[i] == cadenaBuscada) {
            frecuencia++;
        }
    }

    return frecuencia;
}

int main() {
    // Ejemplo de uso
    const int longitudArreglo = 6;
    string arregloCadenas[longitudArreglo] = {"Hola", "Mundo", "Hola", "C++", "Hola", "Programación"};

    string cadenaBuscada = "Hola";
    int frecuencia = calcularFrecuencia(arregloCadenas, longitudArreglo, cadenaBuscada);

    cout << "La cadena '" << cadenaBuscada << "' aparece " << frecuencia << " veces." << endl;

    return 0;
}
