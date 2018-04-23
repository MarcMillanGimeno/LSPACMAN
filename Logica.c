//Inclueixo la llibreria i mòduls que facin falta.
#include "Logica.h"
#include "Grafics.h"
#include <time.h>

//Funcio que retorna el fitxer modificat, i efectua tots els canvis que calen en els camps del fitxer del Pacman.
Fitxer movePacman( Fitxer fitxer, int *ok_mov_pac, int *temps_mov, int *resta_vida, Fitxer fitxer_inicial, int *temps_big_fruit, Fruita_gran *big_fruit, int *big_fruit_ok){
	int compt_fant, mov_pac_realizado;
	
	//Si el jugador a premut alguna fletxa, canvio la direcció del Pacman
	if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT) == 1){
		//Direcció esquerra.
		fitxer.pacman.direccio = 3;
	}
	
	if (LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT) == 1){
		//Direcció dreta.
		fitxer.pacman.direccio = 4;
	}
	
	if (LS_allegro_key_pressed(ALLEGRO_KEY_UP) == 1){
		//Direcció amunt.
		fitxer.pacman.direccio = 1;
	}
	
	if (LS_allegro_key_pressed(ALLEGRO_KEY_DOWN) == 1){
		//Direcció avall.
		fitxer.pacman.direccio = 2;
	}
	
	mov_pac_realizado = 0;
	
	//si han pasat els 0,6 segons el pacman podrá efectuar el seu moviment actual
	if( *ok_mov_pac == 1){
		//Si la direcció es a amunt
		if ( fitxer.pacman.direccio == 1){
			//La casella d'amunt no es una paret 
			if ( fitxer.taulell.caselles[fitxer.pacman.pY - 1][fitxer.pacman.pX].es_paret == 0 ){
				//Mou el pacman
				fitxer.pacman.pY = fitxer.pacman.pY - 1;
				
				//Moviment efectuat
				*ok_mov_pac = 0;
				*temps_mov = 0;
				mov_pac_realizado = 1;
			}
		}
		//Si la direcció es avall 
		if ( fitxer.pacman.direccio == 2){
			//La casella d'avall no es una paret 
			if ( fitxer.taulell.caselles[fitxer.pacman.pY + 1][fitxer.pacman.pX].es_paret == 0 ){
				//Mou el pacman
				fitxer.pacman.pY = fitxer.pacman.pY + 1;
				
				//Moviment efectuat
				*ok_mov_pac = 0;
				*temps_mov = 0;
				mov_pac_realizado = 1;
			}
		}
		//Si la direcció es esquerra 
		if ( fitxer.pacman.direccio == 3){
			//La casella de l'esquerra no es una paret 
			if ( fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX - 1].es_paret == 0 ){
				//Mou el pacman
				fitxer.pacman.pX = fitxer.pacman.pX - 1;
				
				//Moviment efectuat
				*ok_mov_pac = 0;
				*temps_mov = 0;
				mov_pac_realizado = 1;
			}
		}
		//Si la direcció es la dreta
		if ( fitxer.pacman.direccio == 4){
			//La casella de la dreta no es una paret
			if ( fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX + 1].es_paret == 0 ){
				//Mou el pacman
				fitxer.pacman.pX = fitxer.pacman.pX + 1;
				
				//Moviment efectuat
				*ok_mov_pac = 0;
				*temps_mov = 0;
				mov_pac_realizado = 1;
			}
		}
	}
	
	//Després d'haver fet el moviment, comprovo si ha caigut a una casella amb fantasma o amb puntuacio
	if( mov_pac_realizado == 1){
		
		if ( fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX].hi_ha_premi == 1 ){
			//Si hi ha premi petit agafa'l i suma puntuació
			fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX].hi_ha_premi = 0;
			fitxer.pacman.puntuacio = fitxer.pacman.puntuacio + 10;
			
		}else if ( fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX].hi_ha_premi == 2 ){
			//Si hi ha premi gran, agafa'l i suma puntuació
			fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX].hi_ha_premi = 0;
			fitxer.pacman.puntuacio = fitxer.pacman.puntuacio + 40;
			
			//Guarda la posició de la fuita gran per printar la puntuacio +40 per pantalla
			big_fruit->pos_x = fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX].x;
			big_fruit->pos_y = fitxer.taulell.caselles[fitxer.pacman.pY][fitxer.pacman.pX].y;
			*temps_big_fruit = 0;
			*big_fruit_ok = 1;
		}
		
		for( compt_fant = 0 ; compt_fant < 4 ; compt_fant ++){
			//Si el pacman es troba amb algun fantasma i no hi ha restat vida en un rang de 0,6 segons
			if( (*resta_vida == 1) && (fitxer.fantasmes[compt_fant].eX == fitxer.pacman.pX) && (fitxer.fantasmes[compt_fant].eY == fitxer.pacman.pY)){
				//Resta vides pacman
				fitxer.pacman.vides --;
				*resta_vida = 0;
				
				//Mentre no mori, reposiciona personatges
				if( fitxer.pacman.vides > 0 ){
					reposicionaPersonajes( &fitxer, fitxer_inicial);
				}
			}
		}
		compt_fant = 0;
	}
	return fitxer;
}

//Funcio que retorna el fitxer modificat, i efectua tots els canvis que calen en els camps del fitxer dels fantasmes.
Fitxer moveEnemics (Fitxer fitxer, int *ok_mov_ene, int *temps_mov_ene, int *resta_vida, Fitxer fitxer_inicial){
	
	int num, ok_direccio = 0, prova_direccio = 0, compt_fant, necesita_direccio, i;
	
	//Recòrrer els 4 fantasmes
	for( i = 0 ; i < 4 ; i ++){
		
		ok_direccio = 0;
		prova_direccio = 0;
		necesita_direccio = 0;
		//Bucle fins que la direcció nova o antigua del fantasma no sigui la correcta
		while ( ok_direccio == 0 ){
			
			//Quan hi ha una intersecció, tindré que recalcular la direccio del enemic
			if ( fitxer.taulell.caselles[fitxer.fantasmes[i].eY][fitxer.fantasmes[i].eX].es_interseccio == 1 || necesita_direccio == 1 ){
				//Calcula la direcció random
				num = rand() % 4;
				fitxer.fantasmes[i].direccio = num;
				//Variable que li permetrá comprovar si la direcció random pot ser correcta.
				prova_direccio = 1;
				//Variable que fará entrar en aquesta condició
				necesita_direccio = 0;
			}
			
			//Comprova si el moviment o la direcció es correcta.
			if ( (fitxer.taulell.caselles[fitxer.fantasmes[i].eY][fitxer.fantasmes[i].eX].es_interseccio == 0) || (prova_direccio == 1)){
				if( fitxer.fantasmes[i].direccio == 0 && fitxer.taulell.caselles[fitxer.fantasmes[i].eY + 1][fitxer.fantasmes[i].eX].es_paret == 0){
					//PUJA
					fitxer.fantasmes[i].eY = fitxer.fantasmes[i].eY + 1;
					ok_direccio = 1 ; 
				}else if( fitxer.fantasmes[i].direccio == 1 && fitxer.taulell.caselles[fitxer.fantasmes[i].eY - 1][fitxer.fantasmes[i].eX].es_paret == 0){
					//BAIXA
					fitxer.fantasmes[i].eY = fitxer.fantasmes[i].eY - 1;
					ok_direccio = 1 ; 
				}else if( fitxer.fantasmes[i].direccio == 2 && fitxer.taulell.caselles[fitxer.fantasmes[i].eY][fitxer.fantasmes[i].eX - 1].es_paret == 0){
					//ESQUERRA
					fitxer.fantasmes[i].eX = fitxer.fantasmes[i].eX - 1;
					ok_direccio = 1 ;						
				}else if( fitxer.fantasmes[i].direccio == 3 && fitxer.taulell.caselles[fitxer.fantasmes[i].eY][fitxer.fantasmes[i].eX + 1].es_paret == 0){
					//DRETA
					fitxer.fantasmes[i].eX = fitxer.fantasmes[i].eX + 1;
					ok_direccio = 1 ; 
				}
				//Si no hi ha hagut moviment
				if(ok_direccio == 0){
					necesita_direccio = 1;
				}
			}
		}
		
		for( compt_fant = 0 ; compt_fant < 4 ; compt_fant ++){
			//Comprova si algun dels 4 fantasmes a enxampat al pacman
			if( (*resta_vida == 1) && (fitxer.fantasmes[compt_fant].eX == fitxer.pacman.pX) && (fitxer.fantasmes[compt_fant].eY == fitxer.pacman.pY)){
				fitxer.pacman.vides --;
				*resta_vida = 0;
				
				//Si li treu una vida, resposiciona personatges
				if( fitxer.pacman.vides > 0 ){
					reposicionaPersonajes( &fitxer, fitxer_inicial);
				}
			}
		}
		compt_fant = 0;
	}
	*ok_mov_ene = 0;
	*temps_mov_ene = 0;
	return fitxer;
}

//Procediment que fa tornar els personatges a les seves posicions inicials
void reposicionaPersonajes(Fitxer *fitxer, Fitxer fitxer_inicial){
	int i;	
	
	for ( i = 0; i < 4; i ++){
		//Fes que els 4 fantasmes tornin a la seva posició inicial
		fitxer->fantasmes[i].eX = fitxer_inicial.fantasmes[i].eX;
		fitxer->fantasmes[i].eY = fitxer_inicial.fantasmes[i].eY;
		fitxer->fantasmes[i].color = fitxer_inicial.fantasmes[i].color;
		fitxer->fantasmes[i].direccio = fitxer_inicial.fantasmes[i].direccio;
	}
	//Fes que el pacman torni a la seva posició inicial
	fitxer->pacman.pX = fitxer_inicial.pacman.pX;
	fitxer->pacman.pY = fitxer_inicial.pacman.pY;
	fitxer->pacman.direccio = fitxer_inicial.pacman.direccio;
}

//Procediment que omple la variable fitxer desde el fitxer de text.
void ompleCaselles(FILE *f_predeterminat, Fitxer *fitxer, int *error_mapa){
	
	//Declaració de variables útils per al procediment
	int i_lineas_cas, i_char, compt_fantasma = 0, compt_parets = 0, hi_ha_jugador = 0, quatre_fantasmes = 0, una_fruita_ok = 0, parets_ok = 1, ix, iy, ok_culdesacs = 0;
	char linea_caselles[16];
	
	//Inicialització de parametres necesaris
	fitxer->taulell.punts_per_guanyar = 0;
	fitxer->taulell.temps = 0;
	
	//Bucle que recòrrer les lines en vertical del fitxer de text
	for ( i_lineas_cas = 0 ; i_lineas_cas < 15 ; i_lineas_cas ++ ){

		//Llegeix la primera linea del fitxer de text
		fgets(linea_caselles, 16, f_predeterminat);
		i_char = 0;
		
		//Bucle que recòrrer cada caracter de la linia llegida
		for ( i_char = 0 ; i_char < 15 ; i_char ++ ){
			
			if ( linea_caselles[i_char] == 'P'){
				//Omple la casella en cas de que sigui una paret
				fitxer->taulell.caselles[i_lineas_cas][i_char].hi_ha_premi = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret = 1;
				fitxer->taulell.caselles[i_lineas_cas][i_char].x = i_char; 
				fitxer->taulell.caselles[i_lineas_cas][i_char].y = i_lineas_cas;
				
			}else if (linea_caselles[i_char] == 'c'){
				//Omple la casella en cas de que hi hagi un premi petit
				fitxer->taulell.caselles[i_lineas_cas][i_char].hi_ha_premi = 1;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].x = i_char;
				fitxer->taulell.caselles[i_lineas_cas][i_char].y = i_lineas_cas; 
				fitxer->taulell.punts_per_guanyar = fitxer->taulell.punts_per_guanyar + 10;
				una_fruita_ok = 1;
				
			}else if (linea_caselles[i_char] == 'C'){
				//Omple la casella en cas de que hi hagi un premi gran
				fitxer->taulell.caselles[i_lineas_cas][i_char].hi_ha_premi = 2;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].x = i_char;
				fitxer->taulell.caselles[i_lineas_cas][i_char].y = i_lineas_cas;
				fitxer->taulell.punts_per_guanyar = fitxer->taulell.punts_per_guanyar + 40;
				
			}else if (linea_caselles[i_char] == 'i'){
				//Omple la casella en cas de que hi hagi una intersecció i un premi petit
				fitxer->taulell.caselles[i_lineas_cas][i_char].hi_ha_premi = 1;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio = 1;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].x = i_char;
				fitxer->taulell.caselles[i_lineas_cas][i_char].y = i_lineas_cas;
				fitxer->taulell.punts_per_guanyar = fitxer->taulell.punts_per_guanyar + 10;
				una_fruita_ok = 1;
			
			}else if (linea_caselles[i_char] == 'I'){
				//Omple la casella en cas de que hi hagi una intersecció i un premi gran
				fitxer->taulell.caselles[i_lineas_cas][i_char].hi_ha_premi = 2;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio = 1;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].x = i_char;
				fitxer->taulell.caselles[i_lineas_cas][i_char].y = i_lineas_cas;
				fitxer->taulell.punts_per_guanyar = fitxer->taulell.punts_per_guanyar + 40;
				una_fruita_ok = 1;
			
			}else if (linea_caselles[i_char] == 'F'){
				//Omple la casella en cas de que hi hagi un fantasma
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret = 0;
				fitxer->fantasmes[compt_fantasma].eX = i_char;
				fitxer->fantasmes[compt_fantasma].eY = i_lineas_cas;
				
				//Asigna al fantasma el seu color corresponent
				if( compt_fantasma == 0 ){
					//Vermell
					fitxer->fantasmes[compt_fantasma].color = 4;
				
				}else if( compt_fantasma == 1 ){
					//Rosa
					fitxer->fantasmes[compt_fantasma].color = 5;
				
				}else if( compt_fantasma == 2 ){
					//Blau
					fitxer->fantasmes[compt_fantasma].color = 9;
				
				}else if( compt_fantasma == 3 ){
					//Taronja
					fitxer->fantasmes[compt_fantasma].color = 6;
				}
				
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].x = i_char;
				fitxer->taulell.caselles[i_lineas_cas][i_char].y = i_lineas_cas;
				fitxer->taulell.caselles[i_lineas_cas][i_char].hi_ha_premi = 1;
				una_fruita_ok = 1;
				
				fitxer->taulell.punts_per_guanyar = fitxer->taulell.punts_per_guanyar + 10;
				
				//Inicialitzo la direcció a una inexistent per a què els fantasmes comencin quiets
				fitxer->fantasmes[compt_fantasma].direccio = 5;
				
				//Per analitazar els següent fantasma compt_fantasma++
				compt_fantasma ++;
				
				//Controla que hi hagin 4 fantasmes
				if ( compt_fantasma == 4 ){
					quatre_fantasmes = 1;
				}
			
			}else if(linea_caselles[i_char] == 'J'){
				//Omple la casella en cas que hi hagi el Jugador
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio = 0;
				fitxer->taulell.caselles[i_lineas_cas][i_char].x = i_char;
				fitxer->taulell.caselles[i_lineas_cas][i_char].y = i_lineas_cas;
				fitxer->pacman.pX = i_char;
				fitxer->pacman.pY = i_lineas_cas;
				fitxer->pacman.puntuacio = 0;
				fitxer->pacman.vides = 3;
				fitxer->pacman.direccio = 5;
				//Controla que hi hagi un sol jugador
				hi_ha_jugador ++;
			}
		}
		//Llegeixo el \n
		fgets(linea_caselles, 16, f_predeterminat);
	}
	
	//Comprovem que si hi ha cul de sac, la casella sigui una intersecció
	for ( i_lineas_cas = 0 ; i_lineas_cas < 15 ; i_lineas_cas ++ ){

		for ( i_char = 0 ; i_char < 15 ; i_char ++ ){
			
			compt_parets = 0;
			if( fitxer->taulell.caselles[i_lineas_cas][i_char].es_interseccio != 1 && fitxer->taulell.caselles[i_lineas_cas][i_char].es_paret != 1){
				//Compta les parets al voltant de una casella no_interseccio
				if( fitxer->taulell.caselles[i_lineas_cas - 1][i_char].es_paret == 1){
					compt_parets ++;
				}
				if( fitxer->taulell.caselles[i_lineas_cas + 1][i_char].es_paret == 1){
					compt_parets ++;
				}
				if( fitxer->taulell.caselles[i_lineas_cas][i_char - 1].es_paret == 1){
					compt_parets ++;
				}
				if( fitxer->taulell.caselles[i_lineas_cas][i_char + 1].es_paret == 1){
					compt_parets ++;
				}
				//Si té 3 parets al voltat, hauría de ser un cul de sac i tenir interseccio
				if( compt_parets >= 3 ){
					ok_culdesacs = 1;
				}
			}
		}
	}	
	
	//Comprovar parets d'adalt i abaix
	for(ix = 0; ix < 15; ix ++){
		if( fitxer->taulell.caselles[0][ix].es_paret == 0){
			parets_ok = 0;
		}
		if ( fitxer->taulell.caselles[14][ix].es_paret == 0){
			parets_ok = 0;
		}
	}
	//Comprovar parets d'esquerra i dreta
	for(iy = 0; iy < 15; iy ++){
		if( fitxer->taulell.caselles[iy][0].es_paret == 0){
			parets_ok = 0;
		}
		if ( fitxer->taulell.caselles[iy][14].es_paret == 0){
			parets_ok = 0;
		}
	}
	//Comprova si s'ha produit algun error al analitzar el fitxer de text carregat.
	if( hi_ha_jugador != 1 || parets_ok != 1 || quatre_fantasmes != 1 || una_fruita_ok != 1 || ok_culdesacs != 0){
		*error_mapa = 1;
	}
}

//LLegeix el ranquing del fitxer de text rank
void readRanquing(Ranquing ranquing[6], int *ok_ranquing){
	//Declaració de variables
	int compt_jug = 0;
	FILE *rank;
	
	//Obertura del fitxer, mode lectura
	rank = fopen("ranquing.txt","r");
	
	//Comprovació de l'obertura correcta
	if( rank == NULL){
		//Obertura incorrecta
		printf("\n\tError d'obertura del fitxer del ranquing\n");
		*ok_ranquing = 0;
		
	}else{
		//Tractament del fitxer del ranquing
		*ok_ranquing = 1;
		
		//Omple les 5 caselles primeres del ranquing
		for ( compt_jug = 0; compt_jug < 5; compt_jug ++ ){
			//Llegeix el nom del jugador
			fgets( ranquing[compt_jug].nom_jug_ranq, MAXC, rank);
			//Ens carreguem el '\n' per un '\0'
			ranquing[compt_jug].nom_jug_ranq[strlen(ranquing[compt_jug].nom_jug_ranq) - 1] = '\0';
			
			//Llegim la puntuació
			fscanf( rank, "%d", &ranquing[compt_jug].punts_finals);

			//Per saltar el \n que hi ha despres de la puntuació, fem un fgets
			fgets( ranquing[compt_jug+1].nom_jug_ranq, MAXC, rank);
		}
		//Tanquem el fitxer
		fclose(rank);
	}
}

//Actualitza el ranquing del fitxer de text rank
void comprovaRanquing(Fitxer fitxer, Ranquing ranquing[6]){
	
	//Declaració de variables necesàries
	int i, introduit = 0;
	Ranquing aux_rank, aux[6];
	FILE *rank;
	
	//Obertura del fitxer, mode escriptura
	rank = fopen("ranquing.txt","w");
	
	//Comprovació de l'obertura correcta
	
	if( rank == NULL){
		//Obertura incorrecta
		printf("\nError d'obertura del fitxer del ranquing\n");
		
	}else{
		//Tractament del fitxer del ranquing
		
		//copia el nom del jugador y la seva puntuació actual a la variable aux_rank
		strcpy(aux_rank.nom_jug_ranq , fitxer.pacman.nom_jugador);
		aux_rank.punts_finals = fitxer.pacman.puntuacio;

		//comprova si el jugador recent ha entrat al ranquing
		for (i = 0; i < 5; i++){
			//Si no está introduit
			if (introduit == 0){
				//No supera la puntuació del jugador comparat
				if (ranquing[i].punts_finals >= aux_rank.punts_finals ){
					aux[i] = ranquing[i];
					
				}else{
					//Si el supera guarda el jugador de la partida i el següent
					aux[i] = aux_rank;
					introduit = 1;
					aux[i+1] = ranquing[i];
				}
			}else{
				//Guarda el jugador pertinent
				aux[i+1]= ranquing[i];
			}
		}
		
		//Escriu al fitxer rank, el ranquing ja actualitzat
		for (i = 0; i < 5; i++){
			fprintf(rank, "%s\n", aux[i].nom_jug_ranq);
			fprintf(rank, "%d\n", aux[i].punts_finals);
		}
		
		//Tancament del fitxer.
		fclose(rank);
	}
}

