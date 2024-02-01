#include <iostream>
#include <cstdlib>
#include <ctime>

#define SELLERS 10
#define MODELS 15

using namespace std;
int main() {
    int matrix[SELLERS][MODELS];
    // Se genera una matriz aleatoria para cambiar el ejercicio cada vez que se ejecuta
    srand(time(0));  // Para inicializar números verdaderamente aleatorios

    for (int i = 0; i < SELLERS; i++) {
        for (int j = 0; j < MODELS; j++) {
            matrix[i][j] = rand() % 100; // Generamos número aleatorio para cada venta
        }
    }

    // Imprimimos ventas de cada vendedor y modelo
    cout<< "Reporte de ventas de cada vendedor y modelo:" << endl;
    for (int i = 0; i < MODELS; i++) {
      cout<<i<<" ";
    }
    cout<<endl;
    for (int i = 0; i < SELLERS; i++) {
        for (int j = 0; j < MODELS; j++) {
            cout <<""<< matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Calculamos el total de ventas de cada vendedor
    int total_sales[SELLERS] = {0}; // tocó inicializarlo 0 porque se llenaba de números sin sentido
    int total_model_sales[MODELS] = {0};
    for (int i = 0; i < SELLERS; i++){
        for (int j = 0; j < MODELS; j++){
            total_sales[i] += matrix[i][j];
            total_model_sales[j] += matrix[i][j];
        }
    }
    
    cout<<"Las ventas de cada vendedor son: "<<endl;
    for (int i = 0; i < SELLERS; i++){
        cout<<"Vendedor "<<i+1<<": "<<total_sales[i]<<endl;
    }

    cout<<"Las ventas de cada modelo son: "<<endl;
    for (int i = 0; i < MODELS; i++){
        cout<<"Modelo "<<i+1<<": "<<total_model_sales[i]<<endl;
    }

    // Encontramos el vendedor con el mayor número de ventas
    int max_sales = total_sales[0];
    int max_seller = 0;
    for (int i = 1; i < SELLERS; i++){
        if (total_sales[i] > max_sales){
            max_sales = total_sales[i];
            max_seller = i;
        }
    }

    // Imprimimos el vendedor con el mayor número de ventas
    cout << "El vendedor con el mayor número de ventas es el vendedor " << max_seller+1<<endl;
    
    return 0;
}
