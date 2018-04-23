//Defineixo el mòdul de grafics.
#ifndef _GRAFICS_H_
#define _GRAFICS_H_

//Inclueixo la llibrería i mòduls que usaré.

#include "LS_allegro.h"
#include "Tipus.h"
#include "logica.h"

//Defineixo els procediments que executaré en grafics.c

void drawPacman(Fitxer fitxer,int *ok_mov_boca);
void drawTable(int compt_temps, Fitxer fitxer, Ranquing ranquing[6]);
void drawEnemics(Fitxer fitxer);
void drawMap(Fitxer fitxer);
void printaFruitaGran(Fruita_gran big_fruit, int *big_fruit_ok, int *temps_big_fruit );

#endif