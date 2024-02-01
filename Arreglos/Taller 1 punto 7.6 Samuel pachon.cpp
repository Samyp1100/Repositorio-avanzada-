#include <iostream>

using namespace std;

int main() {
    int filas, columnas;
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> columnas;

    
    int matriz[filas][columnas];

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "\nMatriz ingresada:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

 
    int mayor = matriz[0][0];
    int filaMayor = 0, colMayor = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] > mayor) {
                mayor = matriz[i][j];
                filaMayor = i;
                colMayor = j;
            }
        }
    }

    cout << "\nEl mayor elemento de la matriz es: " << mayor << endl;
    cout << "Se encuentra en la posición [" << filaMayor << "][" << colMayor << "]." << endl;

    return 0;
}

