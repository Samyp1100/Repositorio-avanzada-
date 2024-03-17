/**
 * Proyecto final de introduccion a la programacion 2023-01
 *
 *
 *
 * El programa simula de forma sencilla el juego de parques con una ficha.
 *
 * Las fichas se mueven en una trayectoria con tal de llegar a la meta.
 * A diferencia del parques original
 * 
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <algorithm> // Necesario para la función shuffle
#include <cstring> 
#include <vector>
#include <random>


#define MAX_JUGADORES 4
#define MIN_JUGADORES 2
#define MAX_GANADORES 1000
using namespace std;

struct Jugador {
  string nombre;
  int contador_turnos = 0;
  int x;
  int y;
  int x_final;
  int y_final;
  int x_inicial;
  int y_inicial;
};


struct Ganador{
  string nombre;
  int turnos;
};

int menu();
void inicio();
void ranking();
void salir();
int dado();
void seleccion(vector<Jugador> jugadores, vector<int>& turnos);
void mostrar_tablero(vector<Jugador> jugadores, vector<int> turnos);
void cambiar_turno(vector<Jugador>& jugadores, int jugador_en_turno, int indice);
int calcular_trayectoria(vector<Jugador> jugadores,int jugador, int matriz_trayectoria[36][2], int indice);
void guardar_jugador_ganador(Jugador jugador);
void guardar_jugador_historico(int jugador, vector<Jugador> jugadores);
int armar_matriz_trayectoria(int matriz_trayectoria[36][2], int indice);
void capturo_jugador(vector<Jugador>& jugadores, int jugador_en_turno);
void captura_jugador_si_esta_en_mi_casilla_de_salida(vector<Jugador>& jugadores,int jugador_capturado);

int main() {
  srand((unsigned)time(NULL));

  while (true) {
    int opcion = menu();
    switch (opcion) {
    case 1:
      inicio();
      break;

    case 2:
      ranking();
      break;

    case 3:
      salir();
      break;

    default:
      cout << "Opcion invalida, intente de nuevo " << endl;
    }
  }
}
/**
 * Funcion que se encarga de mostrar el menu principal.
 * Esta muestra las opciones al usuario y captura la opcion que desea seguir el
 * usuario
 *
 * retorna: la opcion elegida por el usuario
 */
int menu() {
  int opc = 0;
  cout << "Menu principal. Digite la opcion que desea" << endl;
  cout << "1. Iniciar nueva partida" << endl
       << "2. Mostrar el ranking de la partida" << endl
       << "3. Salir del juego" << endl;
  cout << "Decida: ";
  cin >> opc;
  return opc;
}

/**
 * Funcion se encarga de iniciar una partida.
 * Se solicitan la cantidad de jugadores y los respectivos nombres
 */
void inicio(){
    
	int cantidad_jugadores =0; // Variable para almacenar la cantidad de jugadores
	bool hay_ganador = false;
	// Se solicita al usuario que ingrese la cantidad de jugadores que son entre
	// dos y cuatro
	while (cantidad_jugadores < 2 || cantidad_jugadores > 4) {
		cout << "Digite la cantidad de jugadores que estarán en la partida: ";
	    cin >> cantidad_jugadores;
		if (cantidad_jugadores < 2 || cantidad_jugadores > 4) {
	  		cout << "La cantidad de jugadores debe ser entre 2 y 4" << endl;
		}
	}
	vector<Jugador> jugadores; 
	vector<int> turnos; // Arreglo de enteros para indicar el orden de los turnos
  	// Se solicita al usuario que ingrese el nombre de cada jugador y se almacena
  	// en la estructura correspondiente
	for (int i = 0; i < cantidad_jugadores; i++) {
	    Jugador jugador;
		cout << "Digite el nombre del jugador " << i << ":";
		cin >> jugador.nombre;
		// push_back guarda un elemento en el vector. 
		// Referencia: https://www.programiz.com/cpp-programming/vectors
		jugadores.push_back(jugador); 
		turnos.push_back(i);
	}
	// Se llama a la función seleccion
	seleccion(jugadores, turnos);
	cout << "Orden de los turnos" << endl;
	// Se muestra en pantalla el orden de los turnos utilizando el arreglo
	// turnos
	for (int i = 0; i < cantidad_jugadores; i++) {
		cout << turnos[i] << " ";
	}
	cout << endl;
	
	// dependiendo de la cantidad de jugadores imprimimos la pocicion en general
	// de cada jugador
	for (int i = 0; i < cantidad_jugadores; i++) {
	// el switch nos permite saber que ficha se esta moviendo
		switch (i) {
			case 0:
				jugadores[turnos[i]].x_inicial = 10;
				jugadores[turnos[i]].y_inicial = 8;
				jugadores[turnos[i]].x = 10;
				jugadores[turnos[i]].y = 8;
				jugadores[turnos[i]].x_final = 5;
				jugadores[turnos[i]].y_final = 4;
				break;
			case 1:
				jugadores[turnos[i]].x_inicial = 10;
				jugadores[turnos[i]].y_inicial = 0;
				jugadores[turnos[i]].x = 10;
				jugadores[turnos[i]].y = 0;
				jugadores[turnos[i]].x_final = 7;
				jugadores[turnos[i]].y_final = 4;
				break;
			case 2:
				jugadores[turnos[i]].x_inicial = 0;
				jugadores[turnos[i]].y_inicial = 0;
				jugadores[turnos[i]].x = 0;
				jugadores[turnos[i]].y = 0;
				jugadores[turnos[i]].x_final = 5;
				jugadores[turnos[i]].y_final = 4;
				break;
			case 3:
				jugadores[turnos[i]].x_inicial = 0;
				jugadores[turnos[i]].y_inicial = 8;
				jugadores[turnos[i]].x = 0;
				jugadores[turnos[i]].y = 8;
				jugadores[turnos[i]].x_final = 3;
				jugadores[turnos[i]].y_final = 4;
				break;
		}
	}
	// Se llama a la función mostrar_tableropara imprimir el estado inicial del
	// tablero
	mostrar_tablero(jugadores, turnos);
	// Se inicia un bucle que continuará hasta que haya un ganador
	while (!hay_ganador) {
		// Se repite sobre cada jugador en el orden que establecieron los turnos
		for (int i = 0; i < cantidad_jugadores; i++) {
			cout << "Es turno del jugador " << jugadores[turnos[i]].nombre << endl;
			// Se llama a la función cambiar_turno para que el jugador actual
			// realice su movimiento
			cambiar_turno(jugadores, turnos[i],i);
			// Se incrementa el contador de turnos del jugador actual 
			jugadores[turnos[i]].contador_turnos++; 
			// Se llama a la función mostrar tablero para mostrar el estado actual
			mostrar_tablero(jugadores, turnos);
			// Se verifica si el jugador actual ha alcanzado su posición final
			if (jugadores[turnos[i]].x == jugadores[turnos[i]].x_final && jugadores[turnos[i]].y == jugadores[turnos[i]].y_final) {
			    cout << "El jugador " << jugadores[turnos[i]].nombre << " es el ganador"<< endl;
			    hay_ganador = true;
			    guardar_jugador_ganador(jugadores[turnos[i]]);
			    guardar_jugador_historico(turnos[i], jugadores);
			    break; 
		  	}
		}
	}
}
	/**
	* Funcion que se encarga de mostrar el ranking de jugadores.
	* Esta funcion carga un archivo de texto que contiene dicha información
	* y la muestra en pantalla
	*
	* Si el archivo no existe, la funcion indicara que no hay ranking.
	*/
void ranking(){
    // en esta parte del codigo abrimos un archivo llamado ganadores 
    ifstream file("ganadores.dat", ios::binary);
    cout << "Ganadores" << endl;
    int ganadores = 0;
    vector<Ganador> lista_ganadores;
    //con esta condicion verificamos si el archivo se abrio 
    if (file.good()) {
        //Leer datos del archivo para luego mostrarlo
        file.read(reinterpret_cast<char*>(&ganadores), sizeof(int));
    	for (int i = 0; i < ganadores; i++) {
            Ganador ganador;
            string::size_type size=ganador.nombre.size();
            file.read(reinterpret_cast<char*>(&size), sizeof(string::size_type));
            ganador.nombre.resize(size);
            file.read(&ganador.nombre[0], size);
    		file.read(reinterpret_cast<char*>(&ganador.turnos), sizeof(int));
    		lista_ganadores.push_back(ganador);
    	}
    	
    	for (int i = 0; i < lista_ganadores.size(); i++) {
    	    Ganador ganador = lista_ganadores[i];
    	    cout<< "Ganador: "<<ganador.nombre << " turnos: "<< ganador.turnos<<endl;
    	}
    	cout<< "============"<<endl;
    	file.close();
    } else {
      cout << "No hay registros de partidas" << endl;
    }
	
    string line;
    //de aqui para abajo repetimos esa misma accion con ganadores2,3,4jugadores 
    ifstream ganadores2("ganadores2jugadores.txt");
    cout << "Ganadores con dos jugadores" << endl;
    if (ganadores2.good()) {
      while (getline(ganadores2, line)) {
        cout << line<<endl;
      }
    } else {
      cout << "No hay registros de partidas" << endl;
    }

    ifstream ganadores3("ganadores3jugadores.txt");
    cout << endl << "Ganadores con tres jugadores" << endl;
    if (ganadores3.good()) {
      while (getline(ganadores3, line)) {
        cout << line<<endl;
      }
    } else {
      cout << "No hay registros de partidas" << endl;
    }

    ifstream ganadores4("ganadores4jugadores.txt");
    cout << endl << "Ganadores con cuatro jugadores" << endl;
    if (ganadores4.good()) {
      while (getline(ganadores4, line)) {
        cout << line<<endl;
      }
    } else {
      cout << "No hay registros de partidas" << endl;
    }
    //por ultimo cerramos cada archivo que abrimos
    ganadores2.close();
    ganadores3.close();
    ganadores4.close();
  }
  /**
   * Funcion que simula el comportamiento del dado
   *
   * retorna: un valor valor aleatorio entre 1 y 6
   */
  int dado(){ 
    // returnamos un numero aleatorio con este parametro
    return 1 + rand() % 6;
  }

  /**
   * Función que se encarga de la selección de turnos de cada jugador.
   * Toma un arreglo de turnos y lo reordena
   *
   */
  void seleccion(vector<Jugador> jugadores, vector<int>& turnos){
    // Función para reorganizar el arreglo de forma aleatoria
    // Referencia: https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
    auto rng = default_random_engine {};
    shuffle(begin(turnos), end(turnos), rng);  
  }

  /**
   * Funcion que se encarga de mostrar el tablero de juego.
   *
   * Esta función muestra una representación del tablero teniendo en cuenta
   * el estado del arreglo de jugadores
   */ 
  void mostrar_tablero(vector<Jugador> jugadores, vector<int> turnos) {
    cout << endl;
    int cantidad_jugadores = jugadores.size();
    //estos for nos ayuda que lo que vaya adentro de etos dos sirvan para los cordenadas x,y
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 11; x++) {
        bool flag_player = false;
        //aca verificamos si hay un jugador en la pocision x,y y mostar el numero de jugadro en el tablero 
        for (int i = 0; i < cantidad_jugadores; i++) {
          if (jugadores[turnos[i]].x == x && jugadores[turnos[i]].y == y) {
            cout << "|" << i + 1 << "1|";
            flag_player = true;
          }
        }
        //este if nos sirve para saber si no hay ningun jugador en la pocision x,y para mostrar el contenido del tablero
        if (flag_player == false) {
          if (x == 5 && y == 8) {
            cout << "|10|";
          } else if (x == 10 && y == 4) {
            cout << "|20|";
          } else if (x == 5 && y == 0 && cantidad_jugadores >= 3) {
            cout << "|30|";
          } else if (x == 0 && y == 4 && cantidad_jugadores == 4) {
            cout << "|40|";
          } else if (x == 5 && y > 4 && y < 8) {
            cout << "|1 |";
          } else if (y == 4 && x > 7 && x < 10) {
            cout << "|2 |";
          } else if (x == 5 && y > 0 && y < 4 && cantidad_jugadores >= 3) {
            cout << "|3 |";
          } else if (y == 4 && x > 0 && x < 3 && cantidad_jugadores == 4) {
            cout << "|4 |";
          } else if (x == 0 || x == 10 || y == 0 || y == 8) {
            cout << "|0 |";
          } else {
            cout << "|  |";
          }
        }
      }
      cout << endl;
    }
  }

  /**
   * Funcion que ejecuta el turno de un jugador especifico
   *
   * Esta funcion recibe por parametro el jugador que va a realizar su turno
   * y realiza los respectivos movimientos segun lo que indique la función
   * "dado" y actualiza el arreglo de jugadores.
   *
   * parametros:
   * - jugador_en_turno: representa el índice del jugador del arreglo de
   * jugadores que realizara su turno
   *
   */
  void cambiar_turno(vector<Jugador>& jugadores,int jugador_en_turno, int indice) {
    int opc = 0;
    int cantidad_jugadores = jugadores.size();
    while (opc != 1) {
      cout << "Digite el numero 1 para ejecutar su turno: ";
      cin >> opc;
    }
    int valor_dado = dado();
    cout << "El jugador " << jugadores[jugador_en_turno].nombre << " saco "
         << valor_dado << endl;
    int matriz_trayectoria[36][2];
    // calcular la trayectoria del jugador actual
    int trayectoria = calcular_trayectoria(jugadores, jugador_en_turno, matriz_trayectoria, indice);
    // con este if verificamos si el valor del dado es menor a la trayectoria 
    if (valor_dado < trayectoria) {
      jugadores[jugador_en_turno].x =
          matriz_trayectoria[36 - trayectoria + valor_dado][0];
      jugadores[jugador_en_turno].y =
          matriz_trayectoria[36 - trayectoria + valor_dado][1];
      cout << "El jugador se movió la casilla " << jugadores[jugador_en_turno].x
           << "," << jugadores[jugador_en_turno].y << endl;
      // llamamos a la funcion capturo jugador para saber si el jugador capturo a otro jugador 
      capturo_jugador(jugadores, jugador_en_turno);
    } else {
      cout << "No es una jugada valida, salta turno" << endl;
    }
  }

  void capturo_jugador(vector<Jugador>& jugadores, int jugador_en_turno) {
    //este for nos ayuda para evaluar la cantidad de jugadores ingresados 
    int cantidad_jugadores = jugadores.size();
    for (int i = 0; i < cantidad_jugadores; i++) {
      //este if nos ayuda para que el jugador evaluado no sea el mismo que esta jugando 
      if (i != jugador_en_turno) {
            // este if nos ayuda para saber a que jugador capturaron
            if (jugadores[i].x == jugadores[jugador_en_turno].x &&
                jugadores[i].y == jugadores[jugador_en_turno].y) {
                //el jugador fue capturado poder restablecer sus cordenadas
                jugadores[i].x = jugadores[i].x_inicial;
                jugadores[i].y = jugadores[i].y_inicial;
                cout << "El jugador " << jugadores[jugador_en_turno].nombre
                     << " capturo la pieza de " << jugadores[i].nombre;
                
                //Caso borde: un jugador que está en mi casilla de salida debe ser capturado
                //Cuando me capturan para evitar problemas de impresión en la pantalla
                
                captura_jugador_si_esta_en_mi_casilla_de_salida(jugadores,i);
      
          return;
        }
      }
    }
  }
  
 /**
  * Función que permite capturar un jugador si capturan una pieza y otra pieza esta en casilla de salida
  * del capturado
  * 
  */
void captura_jugador_si_esta_en_mi_casilla_de_salida(vector<Jugador>& jugadores,int jugador_capturado){
    int cantidad_jugadores = jugadores.size();
    for (int i = 0; i < cantidad_jugadores; i++) {
      //este if nos ayuda para que el jugador evaluado no sea el mismo que fue capturado 
      if (i != jugador_capturado) {
            // este if nos ayuda para saber si hay alguien en mi casilla de salida (ya me devolvieron)
            if (jugadores[i].x == jugadores[jugador_capturado].x &&
                jugadores[i].y == jugadores[jugador_capturado].y) {
                //reestablece coordenadas del capturado posterior
                jugadores[i].x = jugadores[i].x_inicial;
                jugadores[i].y = jugadores[i].y_inicial;
                cout << "El jugador " << jugadores[jugador_capturado].nombre
                     << " capturo la pieza de " << jugadores[i].nombre << " dado que esta en la casilla de salida";
                return;
            }
      }
    }
}
  /**
   * Función que calcula la distancia desde la posición del jugador hasta su
   * meta
   *
   * Esta función toma la posición actual y la meta desde la estructura (struct)
   * y calcula la distancia en cuadros teniendo en cuenta la trayectoria de los
   * requerimientos indicados.
   *
   * parámetros:
   * - jugador: representa el índice en el arreglo de jugadores
   *
   * retorna: la distancia en cuadros que hay desde la posición actual del
   * jugador hasta la meta.
   */
  int calcular_trayectoria(vector<Jugador> jugadores, int jugador, int matriz_trayectoria[36][2], int indice) {
    //llamamos a la funcion armar la matriz de trayectoria para construirla 
    int contador_posiciones = armar_matriz_trayectoria(matriz_trayectoria, indice);
    //este for sirve para recorrer la trayectoria de la matriz
    for (int i = 0; i < contador_posiciones; i++) {
      Jugador j = jugadores[jugador];
      //este if nos ayuda para saber si las cordenadas de la pocision actual coinciden con las del jugador 
      if (matriz_trayectoria[i][0] == j.x && matriz_trayectoria[i][1] == j.y) {
        return contador_posiciones - i;
      }
    }
    return -1;
  }

  /**
   * Función que guarda los datos de un jugador que ganó una partida.
   *
   * Esta función abre un archivo y al final escribirá los datos del jugador.
   * Si no existe el archivo, la función lo crea.
   *
   */
  void guardar_jugador_ganador(Jugador jugador) {
    ifstream file2("ganadores.dat", ios::binary);
    int ganadores = 0;
    vector<Ganador> lista_ganadores;
    //con esta condicion verificamos si el archivo se abrio 
    if (file2.good()) {
        //Leer datos del archivo para luego mostrarlo
        file2.read(reinterpret_cast<char*>(&ganadores), sizeof(int));
    	for (int i = 0; i < ganadores; i++) {
    	    Ganador ganador;
            string::size_type size=ganador.nombre.size();
            file2.read(reinterpret_cast<char*>(&size), sizeof(string::size_type));

            ganador.nombre.resize(size);
            file2.read(&ganador.nombre[0], size);

    		file2.read(reinterpret_cast<char*>(&ganador.turnos), sizeof(int));

    	    lista_ganadores.push_back(ganador);
    	}
    }
    file2.close();

    // Copiando el contenido de un string a un arreglo char
    Ganador nuevo_ganador;
    nuevo_ganador.nombre = jugador.nombre;
	nuevo_ganador.turnos = jugador.contador_turnos;
	ganadores++;
	
	lista_ganadores.push_back(nuevo_ganador);
    
    ofstream file("ganadores.dat", ios::out | ios::binary);

    file.write(reinterpret_cast<char*>(&ganadores), sizeof(int));
	for( int i = 0; i< ganadores; i++){
	    Ganador ganador = lista_ganadores[i];
        string::size_type size=ganador.nombre.size();
        file.write(reinterpret_cast<const char*>(&size),sizeof(string::size_type));
        file.write(ganador.nombre.data(),size);
		file.write( reinterpret_cast<const char*>(&ganador.turnos), sizeof(ganador.turnos));
	}
	file.close();
  }
  /**
   * Función que guarda los datos de un jugador que ganó una partida y a los
   * jugadores que derrotó. La función tiene en cuenta la cantidad de jugadores
   * en la partida y así decidirá si lo guarda en un archivo diferente. Es
   * decir, cada archivo que utilice depende de la cantidad de jugadores en las
   * partidas
   *
   * Esta función abre un archivo y al final escribirá los datos de los
   * jugadores. Si no existe el archivo, la función lo crea.
   *
   */
  void guardar_jugador_historico(int jugador, vector<Jugador> jugadores) {
    int cantidad_jugadores = jugadores.size();
    if (cantidad_jugadores == 2) {
      //abrimos el archivo que esta en modo escritura 
      ofstream file("ganadores2jugadores.txt", ios::app);
      //en el archivo escribimos el nombre del ganador, los turnos y a quien derroto
      file << "Ganador: " << jugadores[jugador].nombre
           << ". Turnos: " << jugadores[jugador].contador_turnos
           << ". Oponentes derrotados: ";
      // verifica si el indice actual no es igual al indice del jugador ganador
      for (int i = 0; i < cantidad_jugadores; i++) {
        if (i != jugador) {
          file << jugadores[i].nombre << " ";
        }
      }
      file << "\n";
      //cerramos el archivo
      file.close();
    }else if (cantidad_jugadores == 3) {
      // de aca para abajo hacemos lo mismo pero con los diferentes archivos 
      ofstream file2("ganadores3jugadores.txt", ios::app);
      file2 << "Ganador: " << jugadores[jugador].nombre
            << ". Turnos: " << jugadores[jugador].contador_turnos
            << ". Oponentes derrotados: ";
      for (int i = 0; i < cantidad_jugadores; i++) {
        if (i != jugador) {
          file2 << jugadores[i].nombre << " ";
        }
      }
      file2 << "\n";
      file2.close();
    } else if (cantidad_jugadores == 4) {
      ofstream file3("ganadores4jugadores.txt", ios::app);
      file3 << "Ganador: " << jugadores[jugador].nombre
            << ". Turnos: " << jugadores[jugador].contador_turnos
            << ". Oponentes derrotados: ";
      for (int i = 0; i < cantidad_jugadores; i++) {
        if (i != jugador) {
          file3 << jugadores[i].nombre << " ";
        }
      }
      file3 << "\n";
      file3.close();
    }
  }
  void salir() { 
    exit(0);
  }



int armar_matriz_trayectoria(int matriz_trayectoria[36][2], int indice) {
    int contador_posiciones = 0;
    //calcula basada en el turno del jugador 
    switch (indice) {
    case 0:
      //aca calcula la trayectoria para el jugador cero y en la manera en 
      //la que se mueve dentro del tablero 
      for (int y = 8; y >= 0; y--) {
        matriz_trayectoria[contador_posiciones][0] = 10;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      
      for (int x = 9; x >= 0; x--) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 0;
        contador_posiciones++;
      }
      for (int y = 1; y <= 8; y++) {
        matriz_trayectoria[contador_posiciones][0] = 0;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      for (int x = 1; x <= 5; x++) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 8;
        contador_posiciones++;
      }
      for (int y = 7; y >= 4; y--) {
        matriz_trayectoria[contador_posiciones][0] = 5;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      break;
      //este case para lo mismo pero para el jugador numero uno
    case 1:
      for (int x = 10; x >= 0; x--) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 0;
        contador_posiciones++;
      }
      for (int y = 1; y <= 8; y++) {
        matriz_trayectoria[contador_posiciones][0] = 0;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      for (int x = 1; x <= 10; x++) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 8;
        contador_posiciones++;
      }
      for (int y = 7; y >= 4; y--) {
        matriz_trayectoria[contador_posiciones][0] = 10;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      for (int x = 9; x >= 7; x--) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 4;
        contador_posiciones++;
      }
      
      
      break;
      //este caso es para el jugador numero dos 
    case 2:
      for (int y = 0; y <= 8; y++) {
        matriz_trayectoria[contador_posiciones][0] = 0;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      for (int x = 1; x <= 10; x++) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 8;
        contador_posiciones++;
      }
      for (int y = 7; y >= 0; y--) {
        matriz_trayectoria[contador_posiciones][0] = 10;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      for (int x = 9; x >= 5; x--) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 0;
        contador_posiciones++;
      }
      for (int y = 1; y <= 4; y++) {
        matriz_trayectoria[contador_posiciones][0] = 5;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      
      break;
      //este caso calcula la trayectoria y como se mueve para el jugador tres 
    case 3:
      for (int x = 0; x <= 10; x++) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 8;
        contador_posiciones++;
      }
      for (int y = 7; y >= 0; y--) {
        matriz_trayectoria[contador_posiciones][0] = 10;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      for (int x = 9; x >= 0; x--) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 0;
        contador_posiciones++;
      }
      for (int y = 1; y <= 4; y++) {
        matriz_trayectoria[contador_posiciones][0] = 0;
        matriz_trayectoria[contador_posiciones][1] = y;
        contador_posiciones++;
      }
      for (int x = 1; x <= 3; x++) {
        matriz_trayectoria[contador_posiciones][0] = x;
        matriz_trayectoria[contador_posiciones][1] = 4;
        contador_posiciones++;
      }
      
      break;
    }
    return contador_posiciones;
  }

