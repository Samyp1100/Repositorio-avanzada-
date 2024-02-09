#include <iostream>
#include <cmath>

using namespace std;

bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(numero); ++i) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    const int cantidadNumerosPrimos = 80;
    int tabla[cantidadNumerosPrimos];

    int numeroActual = 2;
    int indice = 0;

    while (indice < cantidadNumerosPrimos) {
        if (esPrimo(numeroActual)) {
            tabla[indice] = numeroActual;
            ++indice;
        }
        ++numeroActual;
    }

    // Imprimir la tabla
    for (int i = 0; i < cantidadNumerosPrimos; ++i) {
        cout << "Primo " << i + 1 << ": " << tabla[i] << endl;
    }

    return 0;
}
