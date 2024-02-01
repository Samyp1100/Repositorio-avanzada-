#include <iostream>

using namespace std;


pair<int*, int> reemplazarDuplicados(int arr[], int tam) {
    int modificaciones = 0;

    for (int i = 0; i < tam; ++i) {
        for (int j = i + 1; j < tam; ++j) {
            if (arr[i] == arr[j]) {
                arr[j] = -5;
                ++modificaciones;
            }
        }
    }

    return make_pair(arr, modificaciones);
}

int main() {
    
    const int tam = 9;
    int miArray[tam] = {1, 2, 3, 2, 4, 5, 4, 6, 7};

    
    pair<int*, int> resultado = reemplazarDuplicados(miArray, tam);

    
    cout << "Arreglo modificado: ";
    for (int i = 0; i < tam; ++i) {
        cout << resultado.first[i] << " ";
    }
    cout << "\nNúmero de entradas modificadas: " << resultado.second << endl;

    return 0;
}


