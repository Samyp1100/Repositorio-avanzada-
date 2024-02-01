#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 10; // Puedes ajustar este valor según tus necesidades

int tablero[MAX];
int n;

bool esSeguro(int fila, int columna) {
    // Verifica si es seguro colocar una reina en la posición (fila, columna)
    for (int i = 0; i < fila; ++i) {
        if (tablero[i] == columna || abs(tablero[i] - columna) == abs(i - fila)) {
            return false;
        }
    }
    return true;
}

void imprimirTablero() {
    // Imprime el tablero con las reinas colocadas
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tablero[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void resolver(int fila) {
    // Resuelve el problema de las N reinas utilizando backtracking
    if (fila == n) {
        // Todas las reinas han sido colocadas, imprime la solución
        imprimirTablero();
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(fila, columna)) {
            // Coloca una reina en la posición actual
            tablero[fila] = columna;

            // Recursivamente coloca las reinas en las filas restantes
            resolver(fila + 1);
        }
    }
}

int main() {
    cout << "Ingrese el valor de n: ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "El valor de n debe estar entre 1 y " << MAX << endl;
        return 1;
    }

    resolver(0); // Comienza desde la fila 0
    return 0;
}