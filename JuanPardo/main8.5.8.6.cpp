/**
* Programa que resuelve los puntos 8.5, 8.6 
*
*/
#include <iostream>
using namespace std;

struct complex_number{
  float real;
  float imag;
};
complex_number add(complex_number a, complex_number b);
complex_number substraction(complex_number a, complex_number b);
complex_number product(complex_number a, complex_number b);
complex_number division(complex_number a, complex_number b);
complex_number conjugate(complex_number a);

int main() {
  cout<<"Calculadora de numeros complejos"<<endl;
  cout<<"Ingrese el primer numero complejo: <parte real> <parte imaginaria> ";
  complex_number a;
  cin>>a.real>>a.imag;
  cout<<"Ingrese el segundo numero complejo: <parte real> <parte imaginaria>: ";
  complex_number b;
  cin>>b.real>>b.imag;
  cout<<"Indique la operación que desea realizar: "<<endl;
  cout<<"1. Suma"<<endl;
  cout<<"2. Resta"<<endl;
  cout<<"3. Multiplicación"<<endl;
  cout<<"4. División"<<endl;
  cout<<"Decida: ";
  int option;
  complex_number result;
  cin>>option;
  switch(option){
    case 1:
      result = add(a,b);
      cout<<"La suma de los numeros complejos es: "<<result.real<<" +("<< result.imag <<")i"<<endl;
      break;
    case 2:
      result = substraction(a,b);
      cout<<"La resta de los numeros complejos es: "<<result.real<<" +("<< result.imag<<")i"<<endl;
      break;
    case 3:
      result = product(a,b);
      cout<<"El producto de los numeros complejos es: "<<result.real<<" +("<< result.imag<<")i"<<endl;
    case 4:
      result = division(a,b);
      cout<<"La division de los numeros complejos es: "<<result.real<<" +("<< result.imag<<")i"<<endl;
      break;
    default:
      cout<<"Opción inválida. Debe elegir un número entre 1 y 4"<<endl;
  }
}

// suma de números complejos
complex_number add(complex_number a, complex_number b){
  complex_number c;
  c.real = a.real + b.real;
  c.imag = a.imag + b.imag;
  return c;
}

// resta de números complejos
complex_number substraction(complex_number a, complex_number b){
  complex_number c;
  c.real = a.real - b.real;
  c.imag = a.imag - b.imag;
  return c;
}

// multiplicación de números complejos
complex_number product(complex_number a, complex_number b){
  complex_number c;
  c.real = a.real * b.real - a.imag * b.imag;
  c.imag = a.real * b.imag + a.imag * b.real;
  return c;
}

// división de números complejos
complex_number division(complex_number a, complex_number b){
  complex_number c;
  complex_number conj = conjugate(b);
  c = product(a, conj);
  complex_number denominator = product(b, conj);
  c.real = c.real / denominator.real;
  c.imag = c.imag / denominator.real;
  return c;
}

// conjugado de un número complejo
complex_number conjugate(complex_number a){
  complex_number c;
  c.real = a.real;
  c.imag = -a.imag;
  return c;
}