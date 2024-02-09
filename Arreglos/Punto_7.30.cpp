#include <string>
#include <iostream>

using namespace std;

int main() {
    string cadena;

    // Ingresa la cadena
    cout << "Ingresa una cadena de caracteres: ";
    getline(cin, cadena);

    // Invierte la cadena
    string cadena_invertida(cadena.rbegin(), cadena.rend());

    // Muestra la cadena invertida
    cout << "Cadena invertida: " << cadena_invertida << endl;

    return 0;
}
