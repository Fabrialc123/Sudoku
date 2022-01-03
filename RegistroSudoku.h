#ifndef REGISTROSUDOKU_H
#define REGISTROSUDOKU_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef struct tRegSudoku {
	int nPuntos;
	string nombreArchivo;
};

bool cargar(tRegSudoku & sudoku, ifstream & infile);

void mostrar(const tRegSudoku & sudoku);

void iniciar(tRegSudoku & registro, string file, int puntos);

bool guardar(const tRegSudoku & registro, ostream & outfile);

bool operator<(const tRegSudoku & regIzq, const tRegSudoku &  regDer);

#endif 


