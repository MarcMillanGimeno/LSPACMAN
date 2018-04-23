//Inclueixo la llibreria i mòduls que facin falta.
#include "LS_allegro.h"
#include "Grafics.h"
#include "Logica.h"

//Procediment que dibuixa el pacman
void drawPacman(Fitxer fitxer, int *ok_mov_boca){
	//Dibuix del pacman basic, unicament el cercle
	al_draw_filled_circle( fitxer.pacman.pX * 40 + 20, fitxer.pacman.pY * 40 + 20, 15, LS_allegro_get_color(YELLOW));
	
	//Ara, segons la direccio en la que vagi el pacman, els ulls y la boca tANCADA tindrán una pocició o una altre
	if( fitxer.pacman.direccio == 4){
		//Direcció RIGHT
		al_draw_filled_circle( fitxer.pacman.pX * 40 + 22, fitxer.pacman.pY * 40 + 11, 3, LS_allegro_get_color(BLACK));
		al_draw_line(fitxer.pacman.pX * 40 + 20 , fitxer.pacman.pY * 40 + 20 , fitxer.pacman.pX * 40 + 40, fitxer.pacman.pY * 40 + 20 , LS_allegro_get_color(BLACK) , 0);
	
	}else if (fitxer.pacman.direccio == 3){
		//Direcció LEFT
		al_draw_filled_circle( fitxer.pacman.pX * 40 + 18, fitxer.pacman.pY * 40 + 11, 3, LS_allegro_get_color(BLACK));
		al_draw_line(fitxer.pacman.pX * 40 + 20 , fitxer.pacman.pY * 40 + 20 , fitxer.pacman.pX * 40, fitxer.pacman.pY * 40 + 20 , LS_allegro_get_color(BLACK) , 0);
	
	}else if (fitxer.pacman.direccio == 2){
		//Direcció DOWN
		al_draw_filled_circle( fitxer.pacman.pX * 40 + 28, fitxer.pacman.pY * 40 + 22, 3, LS_allegro_get_color(BLACK));
		al_draw_line(fitxer.pacman.pX * 40 + 20 , fitxer.pacman.pY * 40 + 20 , fitxer.pacman.pX * 40 + 20, fitxer.pacman.pY * 40 + 40 , LS_allegro_get_color(BLACK) , 0);
	
	}else if (fitxer.pacman.direccio == 1){
		//Direcció UP
		al_draw_filled_circle( fitxer.pacman.pX * 40 + 12, fitxer.pacman.pY * 40 + 22, 3, LS_allegro_get_color(BLACK));
		al_draw_line(fitxer.pacman.pX * 40 + 20 , fitxer.pacman.pY * 40 + 20 , fitxer.pacman.pX * 40 + 20, fitxer.pacman.pY * 40, LS_allegro_get_color(BLACK) , 0);
	}
	
	//Ara dibuixo el moviment de la boca del pacman.
	if( *ok_mov_boca == 1){
		
		//Abro boca
		if( fitxer.pacman.direccio == 4){
			//Direcció RIGHT
			al_draw_filled_triangle (fitxer.pacman.pX * 40 + 20, fitxer.pacman.pY * 40 + 20, fitxer.pacman.pX * 40 + 40, fitxer.pacman.pY * 40 + 40, fitxer.pacman.pX * 40 + 40 , fitxer.pacman.pY * 40 , LS_allegro_get_color(BLACK));
		
		}else if (fitxer.pacman.direccio == 3){
			//Direcció LEFT
			al_draw_filled_triangle (fitxer.pacman.pX * 40 + 20, fitxer.pacman.pY * 40 + 20, fitxer.pacman.pX * 40, fitxer.pacman.pY * 40, fitxer.pacman.pX * 40, fitxer.pacman.pY * 40 + 40, LS_allegro_get_color(BLACK));
		
		}else if (fitxer.pacman.direccio == 2){
			//Direcció DOWN
			al_draw_filled_triangle (fitxer.pacman.pX * 40 + 20, fitxer.pacman.pY * 40 + 20, fitxer.pacman.pX * 40, fitxer.pacman.pY * 40 + 40, fitxer.pacman.pX * 40 + 40, fitxer.pacman.pY * 40 + 40, LS_allegro_get_color(BLACK));
		
		}else if (fitxer.pacman.direccio == 1){
			//Direcció UP
			al_draw_filled_triangle (fitxer.pacman.pX * 40 + 20, fitxer.pacman.pY * 40 + 20, fitxer.pacman.pX * 40, fitxer.pacman.pY * 40, fitxer.pacman.pX * 40 + 40, fitxer.pacman.pY * 40, LS_allegro_get_color(BLACK));
		}
	}
}

//Procediment que dibuixa els fantasmes
void drawEnemics(Fitxer fitxer){
	int indx_fantasma;
	
	//Dibuixa el fantasma que toqui(segons el index), amb el seu color corresponent
	for (indx_fantasma = 0 ; indx_fantasma < 4 ; indx_fantasma ++){
		al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 20, fitxer.fantasmes[indx_fantasma].eY * 40 + 15, 12, LS_allegro_get_color(fitxer.fantasmes[indx_fantasma].color));
		al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 20, fitxer.fantasmes[indx_fantasma].eY * 40 + 23, 4, 10, LS_allegro_get_color(fitxer.fantasmes[indx_fantasma].color));
		al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 12, fitxer.fantasmes[indx_fantasma].eY * 40 + 23, 4, 10, LS_allegro_get_color(fitxer.fantasmes[indx_fantasma].color));
		al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 28, fitxer.fantasmes[indx_fantasma].eY * 40 + 23, 4, 10, LS_allegro_get_color(fitxer.fantasmes[indx_fantasma].color));

		//Depen de la direcció en la que es moguin, els ulls miraran cap un costat o altre.

		if( fitxer.fantasmes[indx_fantasma].direccio == 3){
			//ulls dreta
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 15, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 17, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 2, LS_allegro_get_color(BLACK));
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 25, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 27, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 2, LS_allegro_get_color(BLACK));

		}else if (fitxer.fantasmes[indx_fantasma].direccio == 2){
			//ulls esquerra
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 15, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 13, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 2, LS_allegro_get_color(BLACK));
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 25, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 23, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 2, LS_allegro_get_color(BLACK));
		
		}else if (fitxer.fantasmes[indx_fantasma].direccio == 0){
			//ulls abaix
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 15, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 15, fitxer.fantasmes[indx_fantasma].eY * 40 + 15, 2, LS_allegro_get_color(BLACK));
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 25, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 25, fitxer.fantasmes[indx_fantasma].eY * 40 + 15, 2, LS_allegro_get_color(BLACK));
		
		}else if (fitxer.fantasmes[indx_fantasma].direccio == 1){
			//ulls adalt
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 15, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 15, fitxer.fantasmes[indx_fantasma].eY * 40 + 9, 2, LS_allegro_get_color(BLACK));
			al_draw_filled_ellipse( fitxer.fantasmes[indx_fantasma].eX * 40 + 25, fitxer.fantasmes[indx_fantasma].eY * 40 + 12, 4, 5, LS_allegro_get_color(WHITE));
			al_draw_filled_circle( fitxer.fantasmes[indx_fantasma].eX * 40 + 25, fitxer.fantasmes[indx_fantasma].eY * 40 + 9, 2, LS_allegro_get_color(BLACK));
		}
	}
}

//Procediment que dibuixa el mapa
void drawMap(Fitxer fitxer){
	int indx_x, indx_y;
	
	//Recòrrer les caselles verticals
	for ( indx_y = 0 ; indx_y < 15 ; indx_y ++){
		
		//Recòrrer les caselles horitzontals
		for ( indx_x = 0 ; indx_x < 15 ; indx_x ++){
			
			//Si hi ha premi petit, pintal
			if(fitxer.taulell.caselles[indx_y][indx_x].hi_ha_premi == 1){
				al_draw_filled_circle( fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 20, 5, LS_allegro_get_color(YELLOW) );
			
			//En el cas que la casella tingui un premi gran
			}else if (fitxer.taulell.caselles[indx_y][indx_x].hi_ha_premi == 2){
				
				//Depent de si es par o impar la posició x, dibuixará una cirera o una taronja. Per variar de fruita.
				if( ((int)fitxer.taulell.caselles[indx_y][indx_x].x % 2) == 0){
					
					//CIRERA, part de la fuita.
					al_draw_filled_circle (fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 12, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 25, 8, LS_allegro_get_color(RED));
					al_draw_circle (fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 12, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 25, 9, LS_allegro_get_color(BLACK),2);
					al_draw_filled_circle (fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 28, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 30, 8, LS_allegro_get_color(RED));
					al_draw_circle (fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 28, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 30, 9, LS_allegro_get_color(BLACK),2);
					
					//Cua de la CIRERA
					al_draw_line(fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 14,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 20,fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 30,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 10, al_map_rgba(185,122,87,255), 2);
					al_draw_line(fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 26,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 26,fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 30,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 10, al_map_rgba(185,122,87,255), 2);
				
				}else{
					//Dibuixa una taronja
					//Fruita TARONJA
					al_draw_filled_circle (fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 25, 10, LS_allegro_get_color(ORANGE));
					
					//Cua de la TARONJA
					al_draw_line(fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 18,fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 8, al_map_rgba(185,122,87,255), 3);
					
					//Fulla de la TARONJA
					al_draw_line(fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 12,fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 28,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 7, LS_allegro_get_color(GREEN), 4);
					al_draw_line(fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 24,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 11,fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 27,fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 8, LS_allegro_get_color(GREEN), 3);
				}
				
			//Si la casella es una paret
			}else if (fitxer.taulell.caselles[indx_y][indx_x].es_paret == 1){
				//Paret amb triangles
				al_draw_filled_triangle (fitxer.taulell.caselles[indx_y][indx_x].x * 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 20, LS_allegro_get_color(LIGHT_BLUE));
				al_draw_filled_triangle (fitxer.taulell.caselles[indx_y][indx_x].x * 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 20, LS_allegro_get_color(CYAN));
				al_draw_filled_triangle (fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 20, LS_allegro_get_color(CYAN));
				al_draw_filled_triangle (fitxer.taulell.caselles[indx_y][indx_x].x * 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 40, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 20, LS_allegro_get_color(BLUE));
				al_draw_filled_triangle (fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 20, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 15, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 15, fitxer.taulell.caselles[indx_y][indx_x].x * 40 + 25, fitxer.taulell.caselles[indx_y][indx_x].y * 40 + 15, LS_allegro_get_color(WHITE));
			}
		}
	}
}

//Procediment que dibuixa el taulell de la dreta del joc
void drawTable(int compt_temps, Fitxer fitxer, Ranquing ranquing[6]){
	int fila = 0, colum = 0, i = 0;
	
	for (colum = 0; colum <= 15; colum++){
		//Dibuixa unes línes per veure la separació entre caselles
		al_draw_line(colum * 40 , 0 , colum * 40, 600 , LS_allegro_get_color(BLACK) , 0);
		al_draw_line( 0, fila * 40, 600, fila * 40 , LS_allegro_get_color(BLACK) , 0);
		fila++;
	}
	
	//Dibuixa PACMAN.
	al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(ORANGE), 618, 28, 0, "PAC-MAN");
	al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(YELLOW), 618, 25, 0, "PAC-MAN");
	
	//Dibuixa el titol de temps i el temps corresponent
	al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 620, 80, 0, "TEMPS");
	al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(WHITE), 678, 120, 0, "%d", compt_temps/10);
	
	//Dibuixa el títol de vides
	al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 620, 160, 0, "VIDES");
	if( fitxer.pacman.vides == 3 ){
		//Dibuixa tres figures de PACMAN
		al_draw_filled_circle( 640, 220, 15, LS_allegro_get_color(YELLOW));
		al_draw_filled_triangle( 620, 210, 620, 230, 640, 220, LS_allegro_get_color(BLACK));
		
		al_draw_filled_circle( 690, 220, 15, LS_allegro_get_color(YELLOW));
		al_draw_filled_triangle( 670, 210, 670, 230, 690, 220, LS_allegro_get_color(BLACK));
		
		al_draw_filled_circle( 740, 220, 15, LS_allegro_get_color(YELLOW));
		al_draw_filled_triangle( 720, 210, 720, 230, 740, 220, LS_allegro_get_color(BLACK));
		
	}else if( fitxer.pacman.vides == 2 ){
		//Dibuixa dues figures de PACMAN
		al_draw_filled_circle( 640, 220, 15, LS_allegro_get_color(YELLOW));
		al_draw_filled_triangle( 620, 210, 620, 230, 640, 220, LS_allegro_get_color(BLACK));
		
		al_draw_filled_circle( 690, 220, 15, LS_allegro_get_color(YELLOW));
		al_draw_filled_triangle( 670, 210, 670, 230, 690, 220, LS_allegro_get_color(BLACK));
		
	}else if( fitxer.pacman.vides == 1 ){
		//Dibuixa una figura de PACMAN
		al_draw_filled_circle( 640, 220, 15, LS_allegro_get_color(YELLOW));
		al_draw_filled_triangle( 620, 210, 620, 230, 640, 220, LS_allegro_get_color(BLACK));
		
	}
	//Dibuixa el títol de PUNTS i els punts actuals corresponents
	al_draw_textf( LS_allegro_get_font(3), LS_allegro_get_color(RED), 620, 260, 0, "PUNTS");
	al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(WHITE), 665, 300, 0, "%d", fitxer.pacman.puntuacio);
	
	//Dibuixa el títol RANQUING
	al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(RED), 610, 380, 0, "RANQUING");
	//Dibuixa el corresponent RANQUING.
	for ( i = 0; i < 5; i ++){
		al_draw_textf( LS_allegro_get_font(1), LS_allegro_get_color(WHITE), 610, 420 + (i*40), 0,"%s", ranquing[i].nom_jug_ranq);
		al_draw_textf( LS_allegro_get_font(1), LS_allegro_get_color(WHITE), 720, 420 + (i*40), 0,"%d", ranquing[i].punts_finals);
	}
}

//Dibuixa la puntuació guanyada per la fuita gran +40.
void printaFruitaGran(Fruita_gran big_fruit, int *big_fruit_ok, int *temps_big_fruit){
	
	//Mentre no hi passin més d'un segon es dibuixará +40
	if( *temps_big_fruit < 10 && *big_fruit_ok == 1){
		
		//Si no han passat 0,5 decimes
		if( *temps_big_fruit < 5){
			//Dibuixa el +40 gran
			al_draw_textf( LS_allegro_get_font(2), LS_allegro_get_color(WHITE), big_fruit.pos_x * 40 , big_fruit.pos_y * 40 + 10, 0,"+40");
		}else{
			//Dibuixa el +40 petit
			al_draw_textf( LS_allegro_get_font(1), LS_allegro_get_color(WHITE), big_fruit.pos_x * 40 + 10, big_fruit.pos_y * 40, 0,"+40");
		}
	}else{
		//Si passa el segon, flag i temps a "0".
		*temps_big_fruit = 0;
		*big_fruit_ok = 0;
	}
	
	
}

