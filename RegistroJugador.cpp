#include "RegistroJugador.h"
#include "checkML.h"

void iniciar(tRegJugador & jugador,string id, int puntos)
{
	jugador.id = id;
	jugador.puntos = puntos;
}

void mostrar(const tRegJugador & jugador)
{
	cout << setw(15) << setfill(' ') << left << jugador.id << jugador.puntos;
}

void actualizar(tRegJugador & jugador, int puntos)
{
	jugador.puntos = jugador.puntos + puntos;
}

bool operator<(const tRegJugador & regIzq, const tRegJugador & regDer)
{
	return regIzq.id < regDer.id;
}

bool menorXRanking(const tRegJugador & jug1, const tRegJugador & jug2)
{
	bool mayor;
	if (jug1.puntos > jug2.puntos) { mayor = true; }
	else if (jug2.puntos > jug1.puntos) { mayor = false; }
	else if (jug1 < jug2) {mayor = true; }
	else { mayor = false; }

	return mayor;
}


