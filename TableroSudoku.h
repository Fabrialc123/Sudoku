#ifndef TABLEROSUDOKU_H
#define TABLEROSUDOKU_H
#include "casillasudoku.h"
#include "conjunto1_9.h"
#include <iomanip>
#include <iostream>

using namespace std;
const int NSudoku = 9;
typedef tCasillaSudoku tTableroSudoku[NSudoku][NSudoku];
typedef struct tCoor {
	int fil;
	int col;
};

bool cargar(tTableroSudoku & tablero, string nombreArchivo);

void mostrarT(const tTableroSudoku & tablero);

bool actualizar(tTableroSudoku & tablero, tCoor cor, int num);

bool borrar(tTableroSudoku & tablero, tCoor cor);

void mostrarCandidatos(const tTableroSudoku & tablero, tCoor cor);

void completarSimples(tTableroSudoku & tablero);

int numVacias(const tTableroSudoku & tablero);

void actualizarValores(tTableroSudoku & tablero, int num, tCoor cor);

bool sePuedeIncluir(const tTableroSudoku & tablero, int num, tCoor cor);

#endif 

