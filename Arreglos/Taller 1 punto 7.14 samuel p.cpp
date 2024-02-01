#include <iostream>

using namespace std;


void invertirNumeros(int numeros[], int n) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio < fin) {
       
        swap(numeros[inicio], numeros[fin]);
        inicio++;
        fin--;
    }
}

int main() {
    
    int n;
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    int numeros[n];

    cout << "Ingrese los " << n << " números:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    
    invertirNumeros(numeros, n);


    cout << "Números invertidos: ";
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}

