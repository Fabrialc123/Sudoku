#ifndef REGISTROJUGADOR_H
#define REGISTROJUGADOR_H

#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

typedef struct tRegJugador {
	string id;
	int puntos;
};

void iniciar(tRegJugador & jugador,string id, int puntos);

void mostrar(const tRegJugador & jugador);

void actualizar(tRegJugador & jugador, int puntos);

bool operator<(const tRegJugador & regIzq, const tRegJugador & regDer);

bool menorXRanking(const tRegJugador & jug1, const tRegJugador & jug2);

#endif 

