#include <iostream>

using namespace std;

// Función para codificar la cadena con un cifrado Caesar Shift
string codificarCesar(const string& cadena, int desplazamiento) {
    string resultado = cadena;

    for (char &caracter : resultado) {
        if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
            char base = (caracter >= 'A' && caracter <= 'Z') ? 'A' : 'a';
            caracter = ((caracter - base + desplazamiento) % 26) + base;
        }
    }

    return resultado;
}

int main() {
    // Leer la cadena desde el teclado
    string cadena;
    cout << "Ingresa una cadena: ";
    getline(cin, cadena);

    // Leer el desplazamiento para el cifrado
    int desplazamiento;
    cout << "Ingresa el desplazamiento para el cifrado Caesar: ";
    cin >> desplazamiento;

    // Codificar la cadena
    string cadenaCodificada = codificarCesar(cadena, desplazamiento);

    // Mostrar la cadena original y la codificada
    cout << "Cadena Original: " << cadena << endl;
    cout << "Cadena Codificada: " << cadenaCodificada << endl;

    return 0;
}
