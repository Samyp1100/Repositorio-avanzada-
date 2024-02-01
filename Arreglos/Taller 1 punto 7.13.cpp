#include <iostream>

using namespace std;


struct Simbolo {
    const char* simbolo;
    int valor;
};


string convertirArabigoARomano(int numero) {
    
    const char* simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string resultado = "";

    
    for (int i = 0; i < sizeof(simbolos) / sizeof(simbolos[0]); ++i) {
        
        while (numero >= valores[i]) {
            
            resultado += simbolos[i];
            
            numero -= valores[i];
        }
    }

    return resultado;
}

int main() {
    
    int numeroArabigo;
    cout << "Ingrese un n�mero ar�bigo (1-3999): ";
    cin >> numeroArabigo;

    if (numeroArabigo >= 1 && numeroArabigo <= 3999) {
        string numeroRomano = convertirArabigoARomano(numeroArabigo);
        cout << "N�mero romano: " << numeroRomano << endl;
    } else {
        cout << "Por favor, ingrese un n�mero entre 1 y 3999." << endl;
    }

    return 0;
}


