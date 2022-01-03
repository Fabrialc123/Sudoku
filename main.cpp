
/* Fabrizio Alcaraz Escobar & David del Cerro Dominguez */ 

#include "JuegoSudoku.h"
#include "listaJugadores.h" 
#include "listaSudokus.h"
#include "checkML.h"
using namespace std;



int main(){
	_CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	int opc, opc1, puntos, puntosS;
	string a, nombre;
	tListaSudokus lista;
	tRegJugador jugador;
	tListaJugadores listaJ;
	tRegSudoku nuevoSudoku;
	iniciar(lista); //Iniciar ambas listas
	iniciar(listaJ);
	if (cargar(lista) && cargar(listaJ)) {  //Cargar ambas listas
		tRegSudoku juego;
		opc = menuPrincipal();
		while (opc != 0) {
			if (opc == 1) {
				mostrar(lista);
				cout << "Elige el sudoku que deseas jugar: ";
				cin >> opc1;
				getline(cin, a);
				while (opc1 < 1 || opc1 > lista.cont) {
					cout << "Introduce una opcion correcta: ";
					cin >> opc1;
					getline(cin, a);
				}
				juego = lista.sudoku[opc1 - 1];
				puntos = jugar(juego);
				if (puntos > 0) {
					cout << "Introduce tu identificador: "; //Pregunta por identificador para actualizar o añadir
					cin >> nombre;
					getline(cin, a);
					iniciar(jugador, nombre, puntos);
					actualizar(listaJ, jugador);
				}

			}
			else if (opc == 2) {
				mostrar(listaJ);
			}
			else if (opc == 3) {
				mostrarXRanking(listaJ);
			}
			else if (opc == 4) {
				mostrar(lista);
				cout << "Escribe el nombre del nuevo sudoku: ";
				cin >> nombre;
				getline(cin, a);
				cout << "Numero de puntos del sudoku: ";
				cin >> puntosS;
				getline(cin, a);
				iniciar(nuevoSudoku, nombre, puntosS);
				if (!insertar(lista, nuevoSudoku)) {
					cout << "No se ha podido insertar el nuevo sudoku" << endl;
				}				
			}
			opc = menuPrincipal();
		}
		guardar(lista);
		guardar(listaJ);
		liberar(listaJ);
	}

	return 0;
}