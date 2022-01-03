#include "RegistroSudoku.h"
#include "checkML.h"

bool cargar(tRegSudoku & sudoku, ifstream & infile)
{
	string a, basura;
	int nivel;
	bool cargado = false;
	infile >> a >> nivel;
	if (!infile.fail()) {
		sudoku.nombreArchivo = a;
		sudoku.nPuntos = nivel;
		getline(infile, basura);
		cargado = true;
	}
	return cargado;
}

void mostrar(const tRegSudoku & sudoku)
{
	cout << setw(22) << setfill(' ') << left << sudoku.nombreArchivo;
	cout << setw(5) << left << sudoku.nPuntos;
	cout << endl;
}

void iniciar(tRegSudoku & registro, string file, int puntos)
{
	registro.nombreArchivo = file;
	registro.nPuntos = puntos;
}

bool guardar(const tRegSudoku & registro, ostream & outfile)
{
	bool guardado = false;
	outfile << registro.nombreArchivo;
	if (!outfile.fail()) {
		outfile << " " <<  registro.nPuntos << endl;
		guardado = true;
	}
	return guardado;
}

bool operator<(const tRegSudoku & regIzq, const tRegSudoku & regDer)
{
	bool menor;
	if (regIzq.nPuntos < regDer.nPuntos) { menor = true; }
	else if (regIzq.nPuntos > regDer.nPuntos) menor = false;
	else if (regIzq.nombreArchivo < regDer.nombreArchivo) menor = true;
	else menor = false;

	return menor;
}
