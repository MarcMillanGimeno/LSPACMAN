//Defineixo el mòdul de logica.
#ifndef _LOGICA_H_
#define _LOGICA_H_

//Inclueixo la llibrería i mòduls que usaré

#include "Tipus.h"
#include "LS_allegro.h"
#include "Grafics.h"

//Defineixo els procediments i funcions que executaré en logica.c
Fitxer movePacman(Fitxer fitxer, int *ok_mov_pac, int *temps_mov, int *resta_vida, Fitxer fitxer_inicial, int *temps_big_fruit, Fruita_gran *big_fruit, int *big_fruit_ok);
Fitxer moveEnemics(Fitxer fitxer, int *ok_mov_ene, int *temps_mov_ene, int *resta_vida, Fitxer fitxer_inicial);
void ompleCaselles(FILE *f_predeterminat, Fitxer *fitxer, int *error_mapa);
void readRanquing(Ranquing ranquing[6], int *ok_ranquing);
void comprovaRanquing(Fitxer fitxer, Ranquing ranquing[6]);
void reposicionaPersonajes(Fitxer *fitxer, Fitxer fitxer_inicial);

#endif