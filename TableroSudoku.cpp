#include "TableroSudoku.h"
#include "checkML.h"

bool cargar(tTableroSudoku & tablero, string nombreArchivo)
{
	fstream filein;
	char aux;
	bool cargado = false;
	string a; //Eliminar cosas
	tCoor coord;
	
	filein.open(nombreArchivo);
	if (filein.is_open()) {
		for (int i = 0; i < NSudoku; i++) {
			for (int j = 0; j < NSudoku; j++) {
				filein.get(aux);
				if (aux != ' ') {
					iniciar(tablero[i][j], aux - '0', fija);				
				}
				else { iniciar(tablero[i][j], 0, vacia); }
			}
			getline(filein,a);
		}
		cargado = true;
		for (int i = 0; i < NSudoku; i++) {
			for (int j = 0; j < NSudoku; j++) {
				coord.fil = i;
				coord.col = j;
				actualizarValores(tablero, tablero[i][j].numero, coord);
			}
		}
	}
	

	return cargado;
}

void mostrarT(const tTableroSudoku & tablero)
{
	cout << setw(30) << setfill('-') << "" <<endl;
	for (int i = 0; i < NSudoku; i++) {
		if (i % 3 == 0) {
			if (i!=0) cout << setw(30) << setfill('-') << "" << endl;
		}
		for (int j = 0; j < NSudoku; j++) {
			if (j % 3 == 0) {
				cout << "|";
			}
			cout << " ";
			mostrar(tablero[i][j]);
			cout << " ";
			if (j == NSudoku - 1) {
				cout << "|";
			}
		}
		cout << endl;
	}
	cout << setw(30) << setfill('-') << "" << endl;
}

bool actualizar(tTableroSudoku & tablero, tCoor cor, int num)
{
	bool actualizado = false;
	actualizado = actualizar(tablero[cor.fil][cor.col], num);
	if (actualizado) {
		for (int i = 0; i < NSudoku; i++) {
			quitar(tablero[i][cor.col].conjunto, num); 
			quitar(tablero[cor.fil][i].conjunto, num);//Recorremos la columna de la casilla quitando el numero de conjunto de los demas
		}
		//Buscamos el subcuadrado
		tCoor corSub;
		corSub.fil = cor.fil;
		corSub.col = cor.col;
		actualizarValores(tablero, num, corSub);
	}
	return actualizado;
}

bool borrar(tTableroSudoku & tablero, tCoor cor)
{
	bool borrado = false;
	tCoor cord;
	if (tablero[cor.fil][cor.col].estado == rellena) {
		tablero[cor.fil][cor.col].estado = vacia;
		borrado = true;
		incluir(tablero[cor.fil][cor.col].conjunto, tablero[cor.fil][cor.col].numero);
		for (int i = 0; i < NSudoku; i++) {
			//Columnas
			cord.fil = i;
			cord.col = cor.col;
			if (sePuedeIncluir(tablero, tablero[cor.fil][cor.col].numero, cord)) {
				incluir(tablero[cord.fil][cord.col].conjunto, tablero[cor.fil][cor.col].numero);
			}

			//Filas
			cord.fil = cor.fil;
			cord.col = i;
			if (sePuedeIncluir(tablero, tablero[cor.fil][cor.col].numero, cord)) {
				incluir(tablero[cord.fil][cord.col].conjunto, tablero[cor.fil][cor.col].numero);
			}
		}
	}

	return borrado;
}

void mostrarCandidatos(const tTableroSudoku & tablero, tCoor cor)
{
	if ((cor.fil >= 0 && cor.fil < NSudoku) && (cor.col >= 0 && cor.col < NSudoku)) {
		mostrar(tablero[cor.fil][cor.col].conjunto);
	}
}

void completarSimples(tTableroSudoku & tablero) {
	tCoor cor;
	for (int i = 0; i < NSudoku; i++) {
		for (int j = 0; j < NSudoku; j++) {
			if (actualizarSimple(tablero[i][j])) {
				cor.fil = i;
				cor.col = j;
				actualizarValores(tablero, tablero[i][j].numero, cor);
			}
		}
	}	
}

int numVacias(const tTableroSudoku & tablero)
{
	int cont = 0;
	for (int i = 0; i < NSudoku; i++) {
		for (int j = 0; j < NSudoku; j++) {
			if (tablero[i][j].estado == vacia) {
				cont++;
			}
		}
	}
	return cont;
}

void actualizarValores(tTableroSudoku & tablero, int num,tCoor cor) {
	if (tablero[cor.fil][cor.col].estado != vacia) {
		tCoor aux;
		for (int i = 0; i < NSudoku; i++) {
			quitar(tablero[i][cor.col].conjunto, num);
			quitar(tablero[cor.fil][i].conjunto, num);
		}
		aux.fil = cor.fil / 3;
		aux.col = cor.col / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				quitar(tablero[aux.fil * 3 + i][aux.col * 3 + j].conjunto, num);
			}
		}
	}

}

bool sePuedeIncluir(const tTableroSudoku & tablero, int num, tCoor cor) {
	int i = 0;
	int j;
	bool enc = false;
	while (i < NSudoku && !enc) {
		if (!tablero[i][cor.col].estado == vacia) {
			if (tablero[i][cor.col].numero == num) { enc = true; }
		}
		if (!tablero[cor.fil][i].estado == vacia) {
			if (tablero[cor.fil][i].numero == num) { enc = true; }
		}
		i++;
		
	}
	if (!enc) {
		tCoor aux;
		aux.fil = cor.fil / 3;
		aux.col = cor.col / 3;
		i = 0;
		while (i < 3 && !enc) {
			j = 0;
			while (j < 3 && !enc) {
				if (!tablero[aux.fil * 3 + i][aux.col * 3 + j].estado == vacia) {
					if(tablero[aux.fil * 3 + i][aux.col * 3 + j].numero == num) { enc = true; }
				}
				j++;
			}
			i++;
		}
	}

	return !enc;
}