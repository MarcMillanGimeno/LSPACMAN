//Inclueixo les llibrerias que utilitzaré en el programa.
#include <stdio.h>
#include <time.h>
#include <conio.h>

//Inclueixo els mòduls que faré servir, els vinculo.
#include "LS_allegro.h"
#include "Logica.h"
#include "Grafics.h"
#include "Tipus.h"
#include "Menu.h"

//Em defineixo una constant que utilitzaré en diferents variables.
#define MAXC 20

int main(void){
	
	//**DECLARACIÓ DE VARIABLES**
	
	char nom_partida[MAXC];
	//Declaració d'un fitxer que actuará com a fitxer binari en cas de que calgui utilitzar-lo.
	FILE *f_guardat;
	
	//Declaració totes les variables de tipues enter (int) que faré sevir com a flags.
	int nSortir = 0, ok_mapa = 0, ok_ranquing = 0, mort, guanya, Pause, resta_vida, big_fruit_ok, ok_mov_pac, ok_mov_ene, ok_mov_boca;
	
	//Declaració les variables de tipus enter (int) que utilitzaré per mourem en el temps.
	int compt_temps, temps_mov, temps_boca, temps_big_fruit, temps_mov_ene;
	
	//Declaració de variables que em permetran incrementar el temps.
	float time1, time0;
	
	//Declaració de variables que usen tipus definits en el modul tipus.h
	Fitxer fitxer, fitxer_inicial;
	Fruita_gran big_fruit;
	Ranquing ranquing[6];
	
	//Planto una "semilla" per que quan executi el random em surtin sempre valors aleatoris diferents.
	srand(time(NULL));
	
	do{
		//Crido al procediment Menu per donar al usuari les respectives opcions.
		Menu( &nSortir, &fitxer, nom_partida, &ok_mapa);
		//Procediment per omplir la variable ranquing.
		readRanquing(ranquing, &ok_ranquing);
		
		//Si no hi han errors anteriors, executo el joc
		if( ok_mapa == 1 && nSortir == 0 && ok_ranquing == 1){
			//inicialitzo les variables abans d'usar-les
			mort = 0;
			guanya = 0;
			temps_boca = 0;
			temps_mov = 0;
			temps_mov_ene = 0;
			compt_temps = 0;
			temps_big_fruit = 0;
			big_fruit_ok = 0;
			ok_mov_ene = 0;
			ok_mov_boca = 0;
			ok_mov_pac = 0;
			Pause = 0;
			resta_vida = 0;

			//La variable compt_temps rep el temps corresponent de la variable fitxer
			compt_temps = fitxer.taulell.temps;
			//Guardo les posicions inicials dels elements.
			fitxer_inicial = fitxer;
			//Agafo de referencia un instant en time0
			time0 = (float) clock();
			
			//Creo la pantalla grafica
			LS_allegro_init(800,600,"Pacman");
			
			//Entro en el bucle del joc, fins que s'acabi partida o es prémi la tecla ESC.
			while( nSortir == 0 && mort == 0 && guanya == 0){
				
				//Si es prem "ESC" s'activa flag per poder sortir.
				if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE) == 1){
					nSortir = 1;
				}
				//Agafo referència del temps actual
				time1 = (float) clock();
					
				//Comprovo si ha pasat 0,1 segon
				if((time1 - time0) / (float)CLOCKS_PER_SEC >= 0.1){
					//incremento els temps
					compt_temps ++;
					temps_boca ++;
					temps_mov ++;
					temps_mov_ene ++;
					temps_big_fruit ++;
					
					//Cada 0,6 segons o 6 decimes, el pacman podrà efectuar moviment.
					if( temps_mov == 6 ){
						//variable que controla que no hi puguin restar més d'una vida en menys de 0,6 segons.
						resta_vida = 1;
						ok_mov_pac = 1;
					}
					//Cada 3 decimes, pacman mourà la boca.
					if( temps_boca >= 3){
						ok_mov_boca = 1;
						//Aquesta condició provocará l'altre moviment de boca.
						if ( temps_boca == 6){
							ok_mov_boca = 0;
							temps_boca = 0;
						}
					}
					//Cada 0,6 segons enemic podrà moure's.
					if( temps_mov_ene == 6){
						ok_mov_ene = 1;
					}
					
					//Es planta time0 en aquest instant per poder tornar a tenir la diferencia entre time1 de una decima.
					time0 = (float) clock();
				}
				
				//S'executa movePacman i es retorna el fitxer amb les corresponents rectificacions.
				fitxer = movePacman(fitxer, &ok_mov_pac, &temps_mov, &resta_vida, fitxer_inicial, &temps_big_fruit, &big_fruit, &big_fruit_ok);
				//Si l'enemic pot executar moviment
				if( ok_mov_ene == 1 ){
					//S'executa moveEnemics i es retorna el fitxer amb les corresponents rectificacions.
					fitxer = moveEnemics(fitxer, &ok_mov_ene, &temps_mov_ene, &resta_vida, fitxer_inicial);
				}
				
				//Si no li queden vides al jugador, mor.
				if( fitxer.pacman.vides == 0){
					mort = 1;
				}
				//Si no queden punts a guanyar, guanya.
				if( fitxer.pacman.puntuacio == fitxer.taulell.punts_per_guanyar ){
					guanya = 1;
				}
				
				//Si es prem la tecla "P", "PAUSE".
				if(LS_allegro_key_pressed(ALLEGRO_KEY_P) == 1){
					//Mentre no es torni a pulsar "P".
					while ( Pause == 0){
						//Mostra per pantalla el següent.
						al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(BLUE), 339, 208, 0, "PAUSE");
						al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(BLUE), 150, 310, 0, "(Press 'P' to continue)");
						al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 336, 205, 0, "PAUSE");
						al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(RED), 148, 308, 0, "(Press 'P' to continue)");
						//Pantalla negra.
						LS_allegro_clear_and_paint(BLACK);
				
						if(LS_allegro_key_pressed(ALLEGRO_KEY_P) == 1){
							Pause = 1;
						}
					}
				}
				Pause = 0;
				
				//Si es prem la tecla "G", es guarda partida.
				if ( LS_allegro_key_pressed(ALLEGRO_KEY_G) == 1){
					//Guardo la partida a un fitxer binari
					//S'obre fitxer
					f_guardat = fopen( nom_partida, "wb");
					
					//Es comprova que no hi hagi error d'obertura
					if ( f_guardat == NULL){
						printf("\nError a l'obertura del ficher '%s'\n", nom_partida);
					
					}else{
						//Tractament del fitxer binari, guardo el fitxer de la partida actual al fixer binari
						fitxer.taulell.temps = compt_temps;
						fwrite( &fitxer, sizeof(Fitxer), 1, f_guardat );
						fclose( f_guardat );
					}
				}
				
				//Dibuixa tota la part grafica en aquest ordre.
				drawMap(fitxer);
				drawPacman(fitxer, &ok_mov_boca);
				drawEnemics(fitxer);
				drawTable(compt_temps, fitxer, ranquing);
				printaFruitaGran(big_fruit, &big_fruit_ok,&temps_big_fruit);
				
				//Pantalla negre per sobre printar a sobre.
				LS_allegro_clear_and_paint(BLACK);
			}
			
			//En el cas que jugador a mort
			if( mort == 1 ){
				
				//Pinta per pantalla el següent
				drawMap(fitxer);
				drawPacman(fitxer, &ok_mov_boca);
				drawEnemics(fitxer);
				drawTable(compt_temps, fitxer, ranquing);
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(BLUE), 251, 205, 0, "GAME");
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(BLUE), 251, 305, 0, "OVER");
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 250, 200, 0, "GAME");
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 250, 300, 0, "OVER");
				
				//Comprova si ha entrat en el ranquing
				comprovaRanquing(fitxer, ranquing);
					
			//Si ha guanayt
			}else if( guanya == 1){
							
				//Pinta per pantalla el següent
				drawMap(fitxer);
				drawPacman(fitxer, &ok_mov_boca);
				drawEnemics(fitxer);
				drawTable(compt_temps, fitxer, ranquing);
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(BLUE), 255, 205, 0, "YOU");
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(BLUE), 251, 305, 0, "WIN!!");
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 255, 200, 0, "YOU");
				al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 250, 300, 0, "WIN!!");
				
				//Actualitza el ranquing
				comprovaRanquing(fitxer, ranquing);
			}
			
			//Neteja la llista de comandes
			LS_allegro_console_clear_screen();
			LS_allegro_clear_and_paint(BLACK);
			
			//Si s'ha acabat la partida tanca allegro.
			if( guanya == 1 || mort == 1){
				LS_allegro_exit();
			}
		}
		
	}while ( nSortir == 0 );	
	
	return 0;
}