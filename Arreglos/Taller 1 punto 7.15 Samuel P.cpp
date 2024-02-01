#include <iostream>

using namespace std;


double calcularMediaAritmetica(const double numeros[], int n) {
    double suma = 0.0;

    
    for (int i = 0; i < n; i++) {
        suma += numeros[i];
    }

    
    double media = suma / n;

    return media;
}

int main() {
    
    int n;
    cout << "Ingrese la cantidad de n�meros: ";
    cin >> n;

    
    double numeros[n];

    cout << "Ingrese los " << n << " n�meros:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    
    double mediaAritmetica = calcularMediaAritmetica(numeros, n);
    cout << "La media aritm�tica es: " << mediaAritmetica << endl;

    return 0;
}

