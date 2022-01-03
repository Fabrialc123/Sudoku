#ifndef LISTASUDOKUS_H
#define LISTASUDOKUS_H
#include "RegistroSudoku.h"

const int MAX = 9;
typedef tRegSudoku RegSudoku[MAX];
typedef struct tListaSudokus {
	RegSudoku sudoku;
	int cont;
};

int numElemts(const tListaSudokus & lista);
void iniciar(tListaSudokus & lista);
bool cargar(tListaSudokus & lista);
void mostrar(const tListaSudokus & lista);

bool guardar(const tListaSudokus & lista);

bool buscar(const tListaSudokus lista, string nombArchiv);

bool insertar(tListaSudokus & lista, const tRegSudoku & sudoku);

#endif 

