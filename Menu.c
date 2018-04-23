//Inclueixo les llibreries i mòduls que facin falta.
#include <stdio.h>
#include "Logica.h"
#include "Menu.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAXC 20
#define MAXO 100

//Procediment que s'encarregarà de efectuar totes les funcionalitats del menu inicial, que apareix a la llista de comandes.
void Menu(int *nsurt, Fitxer *fitxer, char nom_partida[MAXC], int *ok_mapa){
	
	//Declaracó de variables
	int opcio, ok, long_opcio, ok_opcio, error_mapa = 0;
	char status[MAXC], opcio_cad[MAXO], status_char, nom_fitxer[MAXC];
	FILE *f_predeterminat, *f_propi, *f_guardats;
	
	
	do{
		ok_opcio = 0;
		
		//Llistat d'opcions inicials
		printf("\n\n\n\n\t\t\t\t LS PACMAN\n\n\n");
		printf("\t1 - Comenzar nova partida\n");
		printf("\t2 - Carregar partida\n");
		printf("\t3 - Sortir\n\n");
		printf("\tOpcio:");
		//Borro el buffer del teclat
		fflush(stdin);
		
		//El programa a de poder llegir cualsevol cosa que l'usuari entri per teclat
		gets(opcio_cad);
		
		long_opcio = strlen( opcio_cad );

		//Si l'opció té més d'un caràcter será erronea
		if( long_opcio > 1 ){
			printf("\n\tERROR!! La opcio nomes pot ser 1, 2 o 3 \n");
			ok_opcio = 0;
			
		}else{
			//Si té un caracter la transformo en un enter
			opcio = opcio_cad[0] - '0';
			
			if( opcio >= 0 && opcio < 4){
				//Si es opcio 1, 2 o 3
				//Correcte
				ok_opcio = 1;
			
			}else{
				//Opcio incorrecta
				printf("\n\tERROR!! La opcio nomes pot ser 1, 2 o 3 \n");
				ok_opcio = 0;
			}
		}
	}while( ok_opcio == 0 );
	
	//clrscr();
	LS_allegro_console_clear_screen();
	
	//Segons l'opció escollida
	switch(opcio){
		
		//Opció 1
		case 1:
			printf("\n\n\n\n\t\t\tCOMENZAR NOVA PARTIDA:\n\n\n");
			printf ("\tIntrodueix el nom de la partida: ");
			//Borra el buffer del teclat
			fflush(stdin);
			
			gets(nom_partida);
			//Introdueixu un .bin al final de la partida per a que si guardo partida estigui en el format correcte.
			strcat(nom_partida, ".bin");

			printf ("\n\tIntrodueix el nom del jugador: ");
			//Borra buffer de teclat
			fflush(stdin);
			
			//Guarda el nom del jugador
			gets(fitxer->pacman.nom_jugador);
			
			//Bucle fins que la opció no sigui si "s" o no "n"
			do{
				ok = 0;
				
				printf ("\n\tVols carregar el mapa per defecte ? <s/n>");
				//Borro buffer del teclat
				fflush(stdin);
				
				gets(status);
	
				//El programa a de poder llegir cualsevol cosa que l'usuari entri per teclat
				long_opcio = strlen( status );
				
				//La cadena llegida ha de ser només un caràcter
				if( long_opcio > 1 ){
					//Error d'opció
					printf("\n\tERROR!! La respota te que ser 's'(SI) o 'n'(NO) \n");
					ok_opcio = 0;
					
				}else{
					//Si es "n" o "s"
					if( status[0] == 's' || status[0] == 'n' ){
						
						status_char = status[0];
						ok = 1;
						
					}else{
						//Error d`opció
						printf("\n\tERROR!! La respota te que ser 's'(SI) o 'n'(NO) \n");
						ok = 0;
					}
				}	
			}while( ok == 0 );
			
			//Quan l'opció es correcta
			if (ok == 1){
				
				if ( status_char == 's'){
					//Obro el fitxer que conté el mapa predeterminat
					f_predeterminat = fopen("mapaOK.txt", "r");
					
					//Controlo l'obertura correcta del fitxer
					if( f_predeterminat == NULL ){
						//Error d'obertura
						printf("\n\tError en l'obertura del fitxer predeterminat\n");
						*ok_mapa = 0;
						
					}else{
						//Si no hi ha error a l'obertura, començo amb el tractament del fitxer .txt
						
						*ok_mapa = 1;
						//Omplo la variable fitxer de dades
						ompleCaselles(f_predeterminat, fitxer, &error_mapa);
						
						//Tanco el fitxer del mapa
						if( error_mapa == 1){
							//Error al analitzar el mapa
							printf("\n\tERROR, el mapa está editat incorrectament");
							*ok_mapa = 0;
						}
						//Tanco el fitxer
						fclose(f_predeterminat);
					}
					
				}else{
					//Mapa editat per l'usuari
					printf("\n\tIntrodueix el nom del fitxer de mapa:");
					//Borro buffer del teclat
					fflush(stdin);
					
					gets(nom_fitxer);
					
					//Obro el fitxer (mode lectura) que conté el mapa predeterminat SECUNDARI
					f_propi = fopen(nom_fitxer, "r");
					
					//Comprovo si està obert correctament
					if( f_propi == NULL ){
						//Error en l'obertura
						printf("\n\tError en l'obertura del fitxer no pre-editat\n");
						*ok_mapa = 0;
						
					}else{
						//Si no hi ha error a l'obertura, començo amb el tractament del fitxer .txt
						*ok_mapa = 1;
						//Omplo la variable fitxer de dades
						ompleCaselles(f_propi, fitxer, &error_mapa);
						
						//Si hi ha hagut algun error en analitzar el fitxer
						if( error_mapa == 1){
							printf("\n\tERROR, el mapa está editat incorrectament");
							*ok_mapa = 0;
						}
						//Tanco el fitxer del mapa
						fclose(f_propi);
					}
				}
			}
			
			break;
		
		//Opció carrega partida
		case 2:
		
			printf("\n\n\n\n\t\t\tCARREGAR PARTIDA DESADA:\n\n\n");
			printf ("\n\tIntrodueix el nom de la partida: ");
			//Borro buffer del teclat
			fflush(stdin);
			
			gets(nom_partida);
			
			//Obro el fitxer binari.
			f_guardats = fopen( nom_partida, "rb");
				
			//Comprovo que està obert correctament
			if ( f_guardats == NULL){
				//Error a l'obertura
				printf("\n\tError a l'obertura del ficher '%s'\n", nom_partida);
				*ok_mapa = 0;
				
			}else{
				//Tractament del fitxer binari
				*ok_mapa = 1;
				//Llegeixo i em guardo la variable fitxer.
				fread(fitxer, sizeof(Fitxer), 1, f_guardats );
				
				//Tancament del fitxer
				fclose( f_guardats );
			}
			break;
		
		//Opció de SORTIR
		case 3:
		
			*nsurt = 1;
			break;
	}
}

