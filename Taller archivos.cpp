#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

const char* seleccionarPalabra(const char* palabras[], int numPalabras) {
    // Selecciona una palabra al azar de la lista
    return palabras[rand() % numPalabras];
}

void mostrarTablero(int intentos, const char* letrasCorrectas, const char* palabra) {
    // Muestra el estado actual del juego
    std::cout << "Intento " << intentos + 1 << std::endl;
    for (size_t i = 0; i < strlen(palabra); ++i) {
        if (strchr(letrasCorrectas, palabra[i]) != nullptr) {
            std::cout << palabra[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

char solicitarLetra(const char* letrasTodas) {
    // Solicita al usuario ingresar una letra, asegurándose de que sea válida
    char letra;
    while (true) {
        std::cout << "Dime una letra: ";
        std::cin >> letra;
        letra = toupper(letra);
        if (strchr(letrasTodas, letra) != nullptr) {
            std::cout << "Esa letra ya la has dicho." << std::endl;
        } else if (!isalpha(letra)) {
            std::cout << "Introduce una letra válida." << std::endl;
        } else {
            break;
        }
    }
    return letra;
}

void guardarPalabraUtilizada(const char* palabra) {
    // Guarda la palabra utilizada en un archivo de texto
    std::ofstream archivo("palabras_utilizadas.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << palabra << std::endl;
        archivo.close();
        std::cout << "Palabra utilizada guardada exitosamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo de palabras utilizadas." << std::endl;
    }
}

void guardarPuntaje(const char* jugador, int puntaje) {
    // Guarda el puntaje del jugador en un archivo de texto
    std::ofstream archivo("puntajes.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << jugador << " " << puntaje << std::endl;
        archivo.close();
        std::cout << "Puntaje guardado exitosamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo de puntajes." << std::endl;
    }
}

void juegoDelAhorcado(const char* palabras[], int numPalabras, const char* fallos[], int numFallos, const char* jugador) {
    // Ejecuta el juego del ahorcado
    srand(static_cast<unsigned>(time(nullptr)));

    const char* palabra = seleccionarPalabra(palabras, numPalabras);
    char letrasCorrectas[26] = "";
    char letrasTodas[26] = "";
    int intentos = 0;

    while (intentos < numFallos - 1) {
        mostrarTablero(intentos, letrasCorrectas, palabra);
        char letra = solicitarLetra(letrasTodas);
        letrasTodas[strlen(letrasTodas)] = letra;

        if (strchr(palabra, letra) != nullptr) {
            letrasCorrectas[strlen(letrasCorrectas)] = letra;
            if (strspn(letrasCorrectas, palabra) == strlen(palabra)) {
                mostrarTablero(intentos, letrasCorrectas, palabra);
                std::cout << "¡Has ganado! La palabra era: " << palabra << std::endl;

                // Guardar palabra utilizada
                guardarPalabraUtilizada(palabra);

                // Guardar puntaje del jugador
                guardarPuntaje(jugador, numFallos - intentos);
                break;
            }
        } else {
            intentos++;
        }

        if (intentos == numFallos - 1) {
            mostrarTablero(intentos, letrasCorrectas, palabra);
            std::cout << "Has perdido. La palabra era: " << palabra << std::endl;
            break;
        }
    }
}

int main() {
    const char* palabras[] = {"SEQUENTIALACCESS", "BUFFER", "FILE"};
    const char* fallos[] = {
        "   !===N\n       N\n       N\n       N\n =======\n",
        "   !===N\n   0   N\n       N\n       N\n =======\n",
        "   !===N\n  _0   N\n       N\n       N\n =======\n",
        "   !===N\n  0  N\n       N\n       N\n =======\n",
        "   !===N\n  0  N\n   |   N\n       N\n =======\n",
        "   !===N\n  0  N\n   |   N\n  /    N\n =======\n",
        "   !===N\n  0  N\n   |   N\n  / \\  N\n =======\n"
    };

    std::cout << "Ingresa tu nombre: ";
    char jugador[100];
    std::cin >> jugador;

    juegoDelAhorcado(palabras, 3, fallos, 7, jugador);

    return 0;
}
