#include <iostream>
using namespace std;

int main() {
    int lista_numeros[] = {3, 8, 1, 6, 2, 9, 4, 7};
    const int longitud = 8;  
    int numero_mayor = lista_numeros[0];
  
    for (int i = 1; i < longitud; ++i) {
        if (lista_numeros[i] > numero_mayor) {
            numero_mayor = lista_numeros[i];
        }
    }
    cout << "El número mayor es: " << numero_mayor <<endl;

    return 0;
}

