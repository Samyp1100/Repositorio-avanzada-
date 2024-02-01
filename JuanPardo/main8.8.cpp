/**
* Programa que resuelve el punto 8.8 
*
*/
#include <iostream>
#include <cmath>

using namespace std;

struct polar_number{
  float radius;
  float angle;
};

// multiplicación de números polares
polar_number product(polar_number a, polar_number b){
  polar_number c;
  c.radius = a.radius * b.radius;
  c.angle = a.angle + b.angle;
  return c;
}

// división de números polares
polar_number division(polar_number a, polar_number b){
  polar_number c;
  c.radius = a.radius / b.radius;
  c.angle = a.angle - b.angle;
  return c;
}

// potencia de números polares
polar_number power(polar_number a, int n){
  polar_number c;
  c.radius = pow(a.radius, n);
  c.angle = n * a.angle;
  return c;
}

