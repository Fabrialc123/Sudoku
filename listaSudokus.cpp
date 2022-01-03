#include "listaSudokus.h"
#include "checkML.h"

int numElemts(const tListaSudokus & lista)
{
	return lista.cont;
}

void iniciar(tListaSudokus & lista)
{
	lista.cont = 0;
}

bool cargar(tListaSudokus & lista)
{
	ifstream filein;
	bool cargado = false;
	bool seguir = true;
	int i = 0;
	filein.open("registroSudokus.txt");
	if (filein.is_open()) {
		while (lista.cont < MAX && seguir) {
			if (cargar(lista.sudoku[lista.cont],filein)) {
				lista.cont++;
				cargado = true;
			}
			else { seguir = false; }
			
		}
	}

	return cargado;
}

void mostrar(const tListaSudokus & lista)
{
	cout << "LISTA DE SUDOKUS REGISTRADOS: " << endl;
	cout << setw(21) << setfill(' ') << right << "FICHERO DE CARGA" << setw(11) << right << "NIVEL" << endl;
	for (int i = 0; i < lista.cont; i++) {
		cout << setw(3) << right << i + 1 << ". ";
		mostrar(lista.sudoku[i]);
	}
}

bool guardar(const tListaSudokus & lista)
{
	bool guardado = false;
	bool seguir = true;
	ofstream outfile;
	outfile.open("RegistrosSS.txt");
	if (outfile.is_open()) {
		guardado = true;
		int i = 0;
		while (i < lista.cont && seguir) {
			if (!guardar(lista.sudoku[i], outfile)) {
				seguir = false;
			}
			i++;
		}
	}
	return guardado;
}

bool buscar(const tListaSudokus lista, string nombArchiv) {
	bool enc = false;
	int i = 0;
	while (i < lista.cont && !enc) {
		if (lista.sudoku[i].nombreArchivo == nombArchiv) {
			enc = true;
		}
		else { i++; }
	}
	return enc;
}

bool insertar(tListaSudokus & lista,const tRegSudoku & sudoku) {
	bool insertado = false;
	bool enc = false;
	int pos = 0;
	if (lista.cont < MAX) {
		if (!(buscar(lista, sudoku.nombreArchivo))) {
			while (pos < lista.cont && !enc) {
				if (sudoku < lista.sudoku[pos]) {
					enc = true;
				}
				else pos++;
			}
			for (int i = lista.cont; i > pos; i--) {
				lista.sudoku[i] = lista.sudoku[i - 1];
			}
			lista.cont++;
			lista.sudoku[pos] = sudoku;
			insertado = true;
		}
		
	}
	return insertado;
}