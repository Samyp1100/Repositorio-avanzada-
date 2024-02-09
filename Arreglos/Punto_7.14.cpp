#include <iostream>

using namespace std;

void invertirArray(int arr[], int tamano) {
    int inicio = 0;
    int fin = tamano - 1;

    while (inicio < fin) {
        // Intercambiar los elementos en las posiciones inicio y fin
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;

        // Mover los índices hacia adentro
        inicio++;
        fin--;
    }
}

int main() {
    const int tamano = 5;  // Puedes ajustar el tamaño del array según tus necesidades
    int numeros[tamano];

    // Ingresa los números
    cout << "Ingresa " << tamano << " números enteros:" << endl;
    for (int i = 0; i < tamano; ++i) {
        cout << "Número " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    // Llama a la función para invertir el array
    invertirArray(numeros, tamano);

    // Muestra el array invertido
    cout << "Array invertido: ";
    for (int i = 0; i < tamano; ++i) {
        cout << numeros[i] << " ";
    }

    return 0;
}
