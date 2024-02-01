#include <iostream>

using namespace std;


struct Complejo {
    double real;
    double imaginario;
};


Complejo sumaComplejos(const Complejo& num1, const Complejo& num2) {
    Complejo resultado;
    resultado.real = num1.real + num2.real;
    resultado.imaginario = num1.imaginario + num2.imaginario;
    return resultado;
}


Complejo restaComplejos(const Complejo& num1, const Complejo& num2) {
    Complejo resultado;
    resultado.real = num1.real - num2.real;
    resultado.imaginario = num1.imaginario - num2.imaginario;
    return resultado;
}


Complejo multiplicacionComplejos(const Complejo& num1, const Complejo& num2) {
    Complejo resultado;
    resultado.real = (num1.real * num2.real) - (num1.imaginario * num2.imaginario);
    resultado.imaginario = (num1.real * num2.imaginario) + (num1.imaginario * num2.real);
    return resultado;
}


Complejo divisionComplejos(const Complejo& num1, const Complejo& num2) {
    Complejo resultado;
    double divisor = (num2.real * num2.real) + (num2.imaginario * num2.imaginario);

    resultado.real = ((num1.real * num2.real) + (num1.imaginario * num2.imaginario)) / divisor;
    resultado.imaginario = ((num1.imaginario * num2.real) - (num1.real * num2.imaginario)) / divisor;

    return resultado;
}

int main() {
    
    Complejo num1, num2;

    cout << "Ingrese el primer número complejo (a bi): ";
    cin >> num1.real >> num1.imaginario;

    cout << "Ingrese el segundo número complejo (a bi): ";
    cin >> num2.real >> num2.imaginario;

    
    Complejo suma = sumaComplejos(num1, num2);
    Complejo resta = restaComplejos(num1, num2);
    Complejo multiplicacion = multiplicacionComplejos(num1, num2);
    Complejo division = divisionComplejos(num1, num2);

    
    cout << "Suma: " << suma.real << " + " << suma.imaginario << "i" << endl;
    cout << "Resta: " << resta.real << " + " << resta.imaginario << "i" << endl;
    cout << "Multiplicación: " << multiplicacion.real << " + " << multiplicacion.imaginario << "i" << endl;
    cout << "División: " << division.real << " + " << division.imaginario << "i" << endl;

    return 0;
}

