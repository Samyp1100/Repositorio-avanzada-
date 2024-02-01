#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Jugador {
    string nombre;
    int intentos;
};

string seleccionarPalabraAleatoria(const string palabras[], int numPalabras) {
    int indice = rand() % numPalabras;
    return palabras[indice];
}

void inicializarJuego(Jugador jugadores[], int numJugadores) {
    for (int i = 0; i < numJugadores; i++) {
        cout << "Ingrese el nombre del jugador: ";
        cin >> jugadores[i].nombre;
        jugadores[i].intentos = 0;
    }
}

void jugarAhorcado(const string palabras[], int numPalabras, Jugador& jugador) {
    string palabraSeleccionada = seleccionarPalabraAleatoria(palabras, numPalabras);
    string palabraAdivinada(palabraSeleccionada.length(), '_');

    while (true) {
        cout << "Palabra a adivinar: " << palabraAdivinada << endl;
        cout << "Ingrese una letra: ";
        char letra;
        cin >> letra;

        bool letraAdivinada = false;

        for (int i = 0; i < palabraSeleccionada.length(); i++) {
            if (palabraSeleccionada[i] == letra) {
                palabraAdivinada[i] = letra;
                letraAdivinada = true;
            }
        }

        if (!letraAdivinada) {
            jugador.intentos++;
            cout << "Letra incorrecta. Intentos restantes: " << 6 - jugador.intentos << endl;
        }

        if (palabraAdivinada == palabraSeleccionada) {
            cout << "¡Felicidades! Has adivinado la palabra: " << palabraAdivinada << endl;
            break;
        }

        if (jugador.intentos == 6) {
            cout << "Lo siento, has alcanzado el límite de intentos. La palabra era: " << palabraSeleccionada << endl;
            break;
        }
    }
}

int main() {
    srand(time(0));

    const int numPalabras = 5;
    string palabras[numPalabras] = {"programacion", "computadora", "cplusplus", "desarrollo", "tecnologia"};

    const int numJugadores = 3;
    Jugador jugadores[numJugadores];

    inicializarJuego(jugadores, numJugadores);

    for (int i = 0; i < numJugadores; i++) {
        cout << "\nTurno de " << jugadores[i].nombre << ":\n";
        jugarAhorcado(palabras, numPalabras, jugadores[i]);
    }

    return 0;
}

