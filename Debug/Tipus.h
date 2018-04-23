//Em defineixo el mòdul dels tipus.
#ifndef _TIPUS_H_
#define _TIPUS_H_
#define MAXC 20

//Declaració tipus Casella
typedef struct{
	float x, y;
	int hi_ha_premi, es_interseccio, es_paret;
}Casella;

//Declaració tipus Taulell
typedef struct{
	int punts_per_guanyar;
	Casella caselles[15][15];
	int temps;
}Taulell;

//Declaració tipus Jugador
typedef struct{
	int puntuacio, pX, pY, vides, direccio;
	char nom_jugador[MAXC];
}Jugador;

//Declaració tipus Fantasma
typedef struct{
	int eX, eY, color, direccio;
}Fantasma;

//Declaració tipus Fitxer
typedef struct{
	Jugador pacman;
	Fantasma fantasmes[4];
	Taulell taulell;
}Fitxer;

//Declaració tipus Ranquing
typedef struct{
	char nom_jug_ranq[MAXC];
	int punts_finals;	
}Ranquing;

//Declaració tipus Fruita_Gran
typedef struct{
	int pos_x, pos_y;
}Fruita_gran;

#endif