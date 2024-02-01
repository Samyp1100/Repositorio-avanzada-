/**
* Programa que resuelve el punto 8.7 
*
*/
#include <iostream>
#include <cmath>

using namespace std;
struct complex_number{
  float real;
  float imag;
};

struct polar_number{
  float radius;
  float angle;
};

// convertir de complejo a polar
polar_number convert_to_polar(complex_number a);
// convertir de polar a complejo
complex_number convert_to_complex(polar_number a);

polar_number convert_to_polar(complex_number a){
  polar_number b;
  b.radius = sqrt(a.real*a.real + a.imag*a.imag);
  b.angle = atan(a.imag/a.real);
  return b;
}

complex_number convert_to_complex(polar_number a){
  complex_number b;
  b.real = a.radius * cos(a.angle);
  b.imag = a.radius * sin(a.angle);
  return b;
}