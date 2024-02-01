#include <iostream>
#include <cstring>

using namespace std;


void desplazarPalabra(char palabra[], int longitud) {
    char temp = palabra[0];

    
    for (int i = 1; i < longitud; i++) {
        palabra[i - 1] = palabra[i];
    }

    
    palabra[longitud - 1] = temp;
}

int main() {
    
    const int longitudMaxima = 100;
    char palabra[longitudMaxima];

    cout << "Ingrese una palabra: ";
    cin >> palabra;

    int longitud = strlen(palabra);

    
    int vecesDesplazar = 3;

    
    for (int i = 0; i < vecesDesplazar; i++) {
        desplazarPalabra(palabra, longitud);
    }

    
    cout << "Palabra desplazada: " << palabra << endl;

    return 0;
}

