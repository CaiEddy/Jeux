#include "Projet_Jeu_3_finale.h"

int selection_3_ou_4(){
	char res_c[100];
	int res;
	printf("Voulez-vous jouer sur un plateau {1} 3x3 ou {2} 4x4 ?\n\n");
	do{
		printf("Saisir 1 ou 2:  ");
		fflush(stdin);
		scanf("%s",res_c);
		if(strcmp(res_c,"1") != 0 && strcmp(res_c,"2") != 0){
			printf("\nErreur de saisie\n\n");
		}
	}while(strcmp(res_c,"1") != 0 && strcmp(res_c,"2") != 0);
	if(strcmp(res_c,"1") == 0){
		res = 1;
	}
	if(strcmp(res_c,"2") == 0){
		res = 2;
	}
	return res;
}

int who_start(char * p1, char * p2){
	int random;
	int first;
	srand(time(NULL));
	random = rand() % 2;
	if(random == 0){
		printf("%s commence avec O\n",p1 );
		printf("%s avec X\n",p2 );
		first = 1;
	}else{
		printf("%s commence avec O\n",p2 );
		printf("%s utilisera X\n",p1 );
		first = 2;
	}
	return first;
}

void allocation(int ** tableau, int taille){
	for(int i=0 ; i < taille ; i++){
		tableau[i] = (int *) malloc(taille * sizeof(int));
	}
}
void initialisation(int ** tableau, int taille){
	for(int i=0 ; i < taille ; i++){
		for(int j=0 ; j < taille ; j++){
			tableau[i][j] = 0;
		}
	}
}
void affichage_jeu(int ** tableau, int taille){
	printf("\n");
	for(int i=0 ; i < taille ; i++){
		for(int j=0 ; j < taille ; j++){
			if(tableau[i][j] == 0){
				printf("_ ");
			}
			if(tableau[i][j] == 1){
				printf("O ");
			}
			if(tableau[i][j] == 2){
				printf("X ");
			}
		}
		printf("\n");
	}
	printf("\n");
}
void request_placement(char * p, int ** tableau, int obj, int taille){
	int ok = 0;
	char l_c[100];
	char c_c[100];
	int l;
	int c;
	if(taille == 3){
		do{
			do{
				printf("\n%s selecte ligne:  ", p);
				fflush(stdin);
				scanf("%s",l_c);
				if(strcmp(l_c, "0") != 0 && strcmp(l_c, "1") != 0 && strcmp(l_c, "2") != 0){
					printf("\nErreur saisie\n\n");
				}
			}while(strcmp(l_c, "0") != 0 && strcmp(l_c, "1") != 0 && strcmp(l_c, "2") != 0);
			do{
				printf("%s selecte colonne:  ", p);
				fflush(stdin);
				scanf("%s",c_c);
				if(strcmp(c_c, "0") != 0 && strcmp(c_c, "1") != 0 && strcmp(c_c, "2") != 0){
					printf("\nErreur saisie\n\n");
				}
			}while(strcmp(c_c, "0") != 0 && strcmp(c_c, "1") != 0 && strcmp(c_c, "2") != 0);
			if(strcmp(l_c, "0") == 0){
				l = 0;
			}
			if(strcmp(l_c, "1") == 0){
				l = 1;
			}
			if(strcmp(l_c, "2") == 0){
				l = 2;
			}
			if(strcmp(c_c, "0") == 0){
				c = 0;
			}
			if(strcmp(c_c, "1") == 0){
				c = 1;
			}
			if(strcmp(c_c, "2") == 0){
				c = 2;
			}
			if(tableau[l][c] != 0){
				printf("\nLa case est deja occupee.\n");
			}else{
				tableau[l][c] = obj;
				ok = 1;
			}
		}while(ok != 1);
	}
	if(taille == 4){
		do{
			do{
				printf("\n%s selecte ligne:  ", p);
				scanf("%s",l_c);
				if(strcmp(l_c, "0") != 0 && strcmp(l_c, "1") != 0 && strcmp(l_c, "2") != 0 && strcmp(l_c, "3") != 0){
					printf("\nErreur saisie\n\n");
				}
			}while(strcmp(l_c, "0") != 0 && strcmp(l_c, "1") != 0 && strcmp(l_c, "2") != 0 && strcmp(l_c, "3") != 0);
			do{
				printf("%s selecte colonne:  ", p);
				scanf("%s",c_c);
				if(strcmp(c_c, "0") != 0 && strcmp(c_c, "1") != 0 && strcmp(c_c, "2") != 0 && strcmp(c_c, "3") != 0){
					printf("\nErreur saisie\n\n");
				}
			}while(strcmp(c_c, "0") != 0 && strcmp(c_c, "1") != 0 && strcmp(c_c, "2") != 0 && strcmp(c_c, "3") != 0);
			if(strcmp(l_c, "0") == 0){
				l = 0;
			}
			if(strcmp(l_c, "1") == 0){
				l = 1;
			}
			if(strcmp(l_c, "2") == 0){
				l = 2;
			}
			if(strcmp(l_c, "3") == 0){
				l = 3;
			}
			if(strcmp(c_c, "0") == 0){
				c = 0;
			}
			if(strcmp(c_c, "1") == 0){
				c = 1;
			}
			if(strcmp(c_c, "2") == 0){
				c = 2;
			}
			if(strcmp(c_c, "3") == 0){
				c = 3;
			}
			if(tableau[l][c] != 0){
				printf("\nLa case est deja occupee.\n");
			}else{
				tableau[l][c] = obj;
				ok = 1;
			}
		}while(ok != 1);
	}
}

int game_egalite(int ** tableau, int taille){
	for(int i=0 ; i < taille ; i++){
		for(int j=0 ; j < taille ; j++){
			if(tableau[i][j] == 0){
				return 0;
			}
		}
	}
	return 1;
}

void resultat(char * p1, char * p2, int pts_1, int pts_2){
	printf("%s a un total de %d points\n",p1, pts_1);
	printf("%s a un total de %d points\n",p2, pts_2);
	if(pts_1 > pts_2){
		printf("\n\nVictoire de %s! Congrats!\n\n",p1 );
	}
	if(pts_1 < pts_2){
		printf("\n\nVictoire de %s! Congrats!\n\n",p2);
	}
	if(pts_1 == pts_2){
		printf("\n\nEgalite\n\n");
	}
}

void play(char * p1, char * p2, int ** tableau, int taille, int first){
	if(first == 1){
		request_placement(p1, tableau, 1, taille);
		affichage_jeu(tableau, taille);
		// check apres chaque coup si victoire ou non
		if(taille == 3){
			if(win_condition_3x3(tableau, first) == 1 ||win_condition_3x3(tableau, first) == 2){
				return;
			}
		}else{
			if(win_condition_4x4(tableau, first) == 1 ||win_condition_4x4(tableau, first) == 2){
				return;
			}
		}
		if(game_egalite(tableau,taille) == 1){
			return;
		}
		request_placement(p2, tableau, 2, taille);
		affichage_jeu(tableau, taille);
		if(taille == 3){
			if(win_condition_3x3(tableau, first) == 1 ||win_condition_3x3(tableau, first) == 2){
				return;
			}
		}else{
			if(win_condition_4x4(tableau, first) == 1 ||win_condition_4x4(tableau, first) == 2){
				return;
			}
		}
		if(game_egalite(tableau,taille) == 1){
			return;
		}
	}else{
		request_placement(p2, tableau, 1, taille);
		affichage_jeu(tableau, taille);
		// check apres chaque coup si victoire ou non
		if(taille == 3){
			if(win_condition_3x3(tableau, first) == 1 ||win_condition_3x3(tableau, first) == 2){
				return;
			}
		}else{
			if(win_condition_4x4(tableau, first) == 1 ||win_condition_4x4(tableau, first) == 2){
				return;
			}
		}
		if(game_egalite(tableau,taille) == 1){
			return;
		}
		request_placement(p1, tableau, 2, taille);
		affichage_jeu(tableau, taille);
		if(taille == 3){
			if(win_condition_3x3(tableau, first) == 1 ||win_condition_3x3(tableau, first) == 2){
				return;
			}
		}else{
			if(win_condition_4x4(tableau, first) == 1 ||win_condition_4x4(tableau, first) == 2){
				return;
			}
		}
		if(game_egalite(tableau,taille) == 1){
			return;
		}
	}
}

int win_condition_3x3(int ** tableau, int first){
	for(int i=0 ; i < TAILLE_3 ; i++){
		for(int j=0 ; j < TAILLE_3 ; j++){
			// win condition
			if(tableau[0][0] == tableau[0][1] && tableau[0][1] == tableau[0][2] && tableau[0][0] != 0){
				if((tableau[0][0] == 1 && first == 1) ||(tableau[0][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[1][0] == tableau[1][1] && tableau[1][1] == tableau[1][2] && tableau[1][0] != 0){
				if((tableau[1][0] == 1 && first == 1) ||(tableau[1][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[2][0] == tableau[2][1] && tableau[2][1] == tableau[2][2] && tableau[2][0] != 0){
				if((tableau[2][0] == 1 && first == 1) ||(tableau[2][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][0] == tableau[1][0] && tableau[1][0] == tableau[2][0] && tableau[0][0] != 0){
				if((tableau[0][0] == 1 && first == 1) ||(tableau[0][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][1] == tableau[1][1] && tableau[1][1] == tableau[2][1] && tableau[0][1] != 0){
				if((tableau[0][1] == 1 && first == 1) ||(tableau[0][1] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][2] == tableau[1][2] && tableau[1][2] == tableau[2][2] && tableau[0][2] != 0){
				if((tableau[0][2] == 1 && first == 1) ||(tableau[0][2] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2] && tableau[0][0] != 0){
				if((tableau[0][0] == 1 && first == 1) ||(tableau[0][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0] && tableau[0][2] != 0){
				if((tableau[0][2] == 1 && first == 1) ||(tableau[0][2] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
		}
	}
	return 0;
}

int win_condition_4x4(int ** tableau, int first){
	for(int i=0 ; i < TAILLE_4 ; i++){
		for(int j=0 ; j < TAILLE_4 ; j++){
			// win condition
			if(tableau[0][0] == tableau[0][1] && tableau[0][1] == tableau[0][2] && tableau[0][2] == tableau[0][3] && tableau[0][0] != 0){
				if((tableau[0][0] == 1 && first == 1) ||(tableau[0][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[1][0] == tableau[1][1] && tableau[1][1] == tableau[1][2] && tableau[1][2] == tableau[1][3] && tableau[1][0] != 0){
				if((tableau[1][0] == 1 && first == 1) ||(tableau[1][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[2][0] == tableau[2][1] && tableau[2][1] == tableau[2][2] && tableau[2][2] == tableau[2][3] && tableau[2][0] != 0){
				if((tableau[2][0] == 1 && first == 1) ||(tableau[2][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[3][0] == tableau[3][1] && tableau[3][1] == tableau[3][2] && tableau[3][2] == tableau[3][3] && tableau[3][0] != 0){
				if((tableau[3][0] == 1 && first == 1) ||(tableau[3][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][0] == tableau[1][0] && tableau[1][0] == tableau[2][0] && tableau[2][0] == tableau[3][0] && tableau[0][0] != 0){
				if((tableau[0][0] == 1 && first == 1) ||(tableau[0][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][1] == tableau[1][1] && tableau[1][1] == tableau[2][1] && tableau[2][1] == tableau[3][1] && tableau[0][1] != 0){
				if((tableau[0][1] == 1 && first == 1) ||(tableau[0][1] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][2] == tableau[1][2] && tableau[1][2] == tableau[2][2] && tableau[2][2] == tableau[3][2] && tableau[0][2] != 0){
				if((tableau[0][2] == 1 && first == 1) ||(tableau[0][2] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][3] == tableau[1][3] && tableau[1][3] == tableau[2][3] && tableau[2][3] == tableau[3][3] && tableau[0][3] != 0){
				if((tableau[0][3] == 1 && first == 1) ||(tableau[0][3] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2] && tableau[2][2] == tableau[3][3] && tableau[0][0] != 0){
				if((tableau[0][0] == 1 && first == 1) ||(tableau[0][0] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
			if(tableau[0][3] == tableau[1][2] && tableau[1][2] == tableau[2][1] && tableau[2][1] == tableau[3][0] && tableau[0][3] != 0){
				if((tableau[0][2] == 1 && first == 1) ||(tableau[0][2] == 2 && first == 2)){
					return 1;
				}else{
					return 2;
				}
			}
		}
	}
	return 0;
}

void jeu(char * p1, char * p2, int ** tableau, int select){
	int t1 = 1;
	int nb_game = 0;
	int first;
	int pts_1 = 0;
	int pts_2 = 0;
	int gagnant = 0;
	system("PAUSE");
	system("CLS");
	printf("Partie %d\n\n\n",(nb_game+1) );
	if(select == 1){
		allocation(tableau, TAILLE_3);
		do{
		// premier tour pour savoir qui commence

			if(t1 == 1){
				initialisation(tableau, TAILLE_3);
				first = who_start(p1,p2);
				t1 = 0;
			}
			play(p1,p2,tableau,TAILLE_3,first);
			gagnant = win_condition_3x3(tableau, first);
			// mise a jour points
			if(gagnant == 1){
				pts_1 = pts_1 + 1;
				nb_game ++;
				t1 = 1;
				printf("La partie est finie, %s gagne 1 point. Congrats!\n\n", p1);
				system("PAUSE");
                system("CLS");
				if(nb_game<MAX_GAME){
                    printf("Partie %d\n\n\n",(nb_game+1));
				}

			}
			if(gagnant == 2){
				pts_2 = pts_2 + 1;
				nb_game ++;
				t1 = 1;
				printf("La partie est finie, %s gagne 1 point. Congrats!\n\n", p2);
				system("PAUSE");
                system("CLS");
				if(nb_game<MAX_GAME){
                    printf("Partie %d\n\n\n",(nb_game+1));
                }
            }
			// if egalite
			if(game_egalite(tableau, TAILLE_3) == 1){
				printf("La partie est finie, il y a egalite!\n\n");
				system("PAUSE");
                system("CLS");
				nb_game ++;
				t1 = 1;
				if(nb_game<MAX_GAME){
                    printf("Partie %d\n\n\n",(nb_game+1));
                }
            }
		}while(nb_game != MAX_GAME);
	}
	if(select == 2){
		allocation(tableau, TAILLE_4);
		do{
		// premier tour pour savoir qui commence

			if(t1 == 1){
				initialisation(tableau, TAILLE_4);
				first = who_start(p1,p2);
				t1 = 0;
			}
			play(p1,p2,tableau,TAILLE_4,first);
			gagnant = win_condition_4x4(tableau, first);
			// mise a jour points
			if(gagnant == 1){
				pts_1 = pts_1 + 1;
				nb_game ++;
				t1 = 1;
				printf("La partie est finie, %s gagne 1 point. Congrats!\n\n", p1);
                system("PAUSE");
                system("CLS");
                if(nb_game<MAX_GAME){
                    printf("Partie %d\n\n\n",(nb_game+1));
                }
            }
			if(gagnant == 2){
				pts_2 = pts_2 + 1;
				nb_game ++;
				t1 = 1;
				printf("La partie est finie, %s gagne 1 point. Congrats!\n\n", p2);
				system("PAUSE");
                system("CLS");
				if(nb_game<MAX_GAME){
                    printf("Partie %d\n\n\n",(nb_game+1));
                }
            }
			// if egalite
			if(game_egalite(tableau, TAILLE_4) == 1){
				printf("La partie est finie, il y a egalite\n\n");
				system("PAUSE");
                system("CLS");
                nb_game ++;
				t1 = 1;
                if(nb_game<MAX_GAME){
                    printf("Partie %d\n\n\n",(nb_game+1));
                }
            }
		}while(nb_game != MAX_GAME);
	}
	resultat(p1,p2,pts_1,pts_2);
}

void jeu_3(char * pseudo_1, char * pseudo_2){

	printf("========================================= MORPION =========================================\n\n\n");
	// affichage regle
	printf("Bienvenue a vous!\n\n\n");
    printf("REGLES DU JEU\n\n");
    printf("Le but du jeu est simple, a tour de role, vous placerez votre O ou votre X sur le plateau.\n");
    printf("Pour gagner, il faudra aligner 3 ou 4 pions (selon le plateau).\n");
    printf("Attention! Nous sommes en informatique:\n");
    printf("La premiere ligne est d'indice 0 et la première colonne aussi!\n");
    printf("Le gagnant sera designe apres 4 parties successives.\n");
    printf("Alors, qui sera le plus rapide? le plus strategique?\n\n");
    printf("C'est parti, let's go!\n\n");


	// selection 3x3 ou 4x4
	int select;
	char choix[100];
	do{
		select = selection_3_ou_4();

		// tableau dynamique
		if(select == 1){
			int *tableau[TAILLE_3];
			jeu(pseudo_1,pseudo_2,tableau,select);
		}
		if(select == 2){
			int * tableau[TAILLE_4];
			jeu(pseudo_1,pseudo_2,tableau,select);
		}
		do{
			printf("\nVoulez-vous rejouer?\n\n");
			printf("Saisir oui ou non:  ");
            fflush(stdin);
            scanf("%s",choix);
            printf("\n");
            if(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0){
                printf("\nErreur de saisie\n\n");
            }
        }while(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0);
	}while(strcmp(choix,"oui") == 0);

	return;
}
