#include "Projet_Jeu_2_finale.h"

	char c0[] = "Pierre";
	char c1[] = "Feuille";
	char c2[] = "Puits";
	char c3[] = "Ciseaux";

void allocation_mot(char ** tableau){
	for(int i=0 ; i < NB_CHOIX ; i++){
		tableau[i] = (char *) malloc(TAILLE_MAX_MOT * sizeof(char));
	}
}

void choix_pour_revanche(char ** tableau, char *choix_1, char *choix_2){
	for(int i=0 ; i < NB_CHOIX ; i++){
		if(strcmp(tableau[i], choix_1) == 0){
			for(int j=i ; j < NB_CHOIX - 1 ; j++){
				tableau[j] = tableau[j+1];
			}
		}
	}
	for(int i=0 ; i < NB_CHOIX ; i++){
		if(strcmp(tableau[i], choix_2) == 0){
			for(int j=i ; j < NB_CHOIX - 1 ; j++){
				tableau[j] = tableau[j+1];
			}
		}
	}
}

void choix_pour_revanche_indice(int * tableau, int choix_1, int choix_2){
	for(int i=0 ; i < NB_CHOIX ; i++){
		if(choix_1 == tableau[i]){
			for(int j=i ; j < NB_CHOIX - 1 ; j++){
				tableau[j] = tableau[j+1];
			}
		}
	}

	for(int i=0; i < NB_CHOIX ; i++){
		if(choix_2 == tableau[i]){
			for(int j=i ; j < NB_CHOIX - 1 ; j++){
				tableau[j] = tableau[j+1];
			}
		}
	}
}

int duel_c1_vs_c2(int choix_1, int choix_2){
	if ((choix_1 == 3 && choix_2 == 1) || (choix_1 == 2 && choix_2 == 3) || (choix_1 == 2 && choix_2 == 0) || (choix_1 == 0 && choix_2 == 3) || (choix_1 == 1 && choix_2 == 2) || (choix_1 == 1 && choix_2 == 0)){
		return 1;
	}
	if((choix_2 == 3 && choix_1 == 1) || (choix_2 == 2 && choix_1 == 3) || (choix_2 == 2 && choix_1 == 0) || (choix_2 == 0 && choix_1 == 3) || (choix_2 == 1 && choix_1 == 2) || (choix_2 == 1 && choix_1 == 0)){
		return 0;
	}
	return 2;
}



void jeu_2(char * pseudo_1, char * pseudo_2){

	printf("==================================== PIERRE FEUILLE PUITS CISEAUX ====================================\n\n\n");
	// affichage regle
	printf("Bienvenue a vous!\n\n\n");
    printf("REGLES DU JEU\n\n");
    printf("Le but du jeu est simple, a tour de role, vous choisirez un signe parmi pierre, feuille, puits, ou ciseaux.\n");
    printf("Les ciseaux coupent la feuille.\n");
    printf("Les ciseaux tombent dans le puits.\n");
    printf("La pierre tombe dans le puits.\n");
    printf("La pierre brise les ciseaux.\n");
    printf("La feuille recouvre le puits.\n");
    printf("La feuille recouvre la pierre.\n\n");
    printf("C'est compris? Alors c'est parti!\n\n\n");
    system("PAUSE");
    system("CLS");


	// allocation tableau de choix
	char *choix_possible_revanche[NB_CHOIX]; allocation_mot(choix_possible_revanche);
	choix_possible_revanche[0] = c0;
	choix_possible_revanche[1] = c1;
	choix_possible_revanche[2] = c2;
	choix_possible_revanche[3] = c3;

	int choix_1;
	char choix_1_c[100];
	int choix_2;
	char choix_2_c[100];
	int loser;
	int revanche;
	char faire_revanche[3];
	char choix[100]; // si on continue ou non
	int pts_1 =0;
	int pts_2 =0;
	do{
		choix_possible_revanche[0] = c0;
		choix_possible_revanche[1] = c1;
		choix_possible_revanche[2] = c2;
		choix_possible_revanche[3] = c3;
		int tableau_choix_indice[NB_CHOIX] = {0,1,2,3};
		printf("%s choisit: {0} Pierre {1} Feuille {2} Puits {3} Ciseaux\n\n",pseudo_1);
		do{
			printf("Saisir: 0 , 1 , 2 ou 3:  ");
			fflush(stdin);
			scanf("%s",choix_1_c);
			if(strcmp(choix_1_c,"0") != 0 && strcmp(choix_1_c,"1") != 0 && strcmp(choix_1_c,"2") != 0 && strcmp(choix_1_c,"3") != 0){
				printf("\nErreur de saisie\n\n");
			}
		}while(strcmp(choix_1_c,"0") != 0 && strcmp(choix_1_c,"1") != 0 && strcmp(choix_1_c,"2") != 0 && strcmp(choix_1_c,"3") != 0);
		if(strcmp(choix_1_c,"0") == 0){
			choix_1 = 0;
		}
		if(strcmp(choix_1_c,"1") == 0){
			choix_1 = 1;
		}
		if(strcmp(choix_1_c,"2") == 0){
			choix_1 = 2;
		}
		if(strcmp(choix_1_c,"3") == 0){
			choix_1 = 3;
		}
		system("CLS");

		printf("%s choisit: {0} Pierre {1} Feuille {2} Puits {3} Ciseaux\n\n",pseudo_2);
		do{
			printf("Saisir: 0 , 1 , 2 ou 3:  ");
			fflush(stdin);
			scanf("%s",choix_2_c);
			if(strcmp(choix_2_c,"0") != 0 && strcmp(choix_2_c,"1") != 0 && strcmp(choix_2_c,"2") != 0 && strcmp(choix_2_c,"3") != 0){
				printf("\nErreur de saisie\n\n");
			}
		}while(strcmp(choix_2_c,"0") != 0 && strcmp(choix_2_c,"1") != 0 && strcmp(choix_2_c,"2") != 0 && strcmp(choix_2_c,"3") != 0);
		if(strcmp(choix_2_c,"0") == 0){
			choix_2 = 0;
		}
		if(strcmp(choix_2_c,"1") == 0){
			choix_2 = 1;
		}
		if(strcmp(choix_2_c,"2") == 0){
			choix_2 = 2;
		}
		if(strcmp(choix_2_c,"3") == 0){
			choix_2 = 3;
		}
		system("CLS");

		if(duel_c1_vs_c2(choix_1, choix_2) == 1){
			printf("%s gagne. Congrats!\n\n",pseudo_1);
			pts_1 = pts_1 + 1;
			loser = 2;
			revanche = 1;
		}else{
			if(duel_c1_vs_c2(choix_1, choix_2) == 0){
				printf("%s gagne. Congrats!\n\n",pseudo_2);
				pts_2 = pts_2 + 1;
				loser = 1;
				revanche = 1;
			}else{
				revanche = 0;
				printf("Egalite! Rejouez\n\n\n");
			}
		}
		if(revanche == 1){
			if(loser == 1){
				printf("%s, veux-tu faire une revanche?\n\n",pseudo_1);
				do{
					printf("Saisir une reponse: oui ou non:  ");
					fflush(stdin);
					scanf("%s",faire_revanche);
					if(strcmp(faire_revanche,"oui") != 0 && strcmp(faire_revanche,"non") != 0){
                		printf("\nErreur de saisie\n\n");
            		}
        		}while(strcmp(faire_revanche,"oui") != 0 && strcmp(faire_revanche,"non") != 0);
			}else{
				printf("%s, veux-tu faire une revanche?\n\n",pseudo_2);
				do{
					printf("Saisir une reponse: oui ou non:  ");
					fflush(stdin);
					scanf("%s",faire_revanche);
					if(strcmp(faire_revanche,"oui") != 0 && strcmp(faire_revanche,"non") != 0){
                		printf("\nErreur de saisie\n\n");
            		}
        		}while(strcmp(faire_revanche,"oui") != 0 && strcmp(faire_revanche,"non") != 0);

			}
			if(strcmp(faire_revanche,"oui") == 0){
				choix_pour_revanche(choix_possible_revanche, choix_possible_revanche[choix_1], choix_possible_revanche[choix_2]);
				choix_pour_revanche_indice(tableau_choix_indice, choix_1, choix_2);
                printf("\n");
                system("PAUSE");
                system("CLS");
				printf("%s choisit: {%d} %s ou {%d} %s\n\n",pseudo_1, tableau_choix_indice[0], choix_possible_revanche[0], tableau_choix_indice[1], choix_possible_revanche[1]);
				do{
					printf("Saisir: %d ou %d:  ",tableau_choix_indice[0],tableau_choix_indice[1] );
					scanf("%d",&choix_1);
					if(choix_1 != tableau_choix_indice[0] && choix_1 != tableau_choix_indice[1]){
						printf("\nErreur de saisie\n\n");
					}
				}while(choix_1 != tableau_choix_indice[0] && choix_1 != tableau_choix_indice[1]);
				system("CLS");


				printf("%s choisit: {%d} %s ou {%d} %s\n\n",pseudo_2, tableau_choix_indice[0], choix_possible_revanche[0], tableau_choix_indice[1], choix_possible_revanche[1]);
				do{
					printf("Saisir: %d ou %d:  ",tableau_choix_indice[0],tableau_choix_indice[1] );
					scanf("%d",&choix_2);
					if(choix_2 != tableau_choix_indice[0] && choix_2 != tableau_choix_indice[1]){
						printf("\nErreur de saisie\n\n");
					}
				}while(choix_2 != tableau_choix_indice[0] && choix_2 != tableau_choix_indice[1]);
				system("CLS");

				if(duel_c1_vs_c2(choix_1,choix_2) == 1){
					pts_1 = pts_1 + 1;
					printf("%s gagne. Congrats!\n\n",pseudo_1);
				}
				if(duel_c1_vs_c2(choix_1,choix_2) == 0){
					pts_2 = pts_2 + 1;
					printf("%s gagne. Congrats!\n\n",pseudo_2);
				}
				if(duel_c1_vs_c2(choix_1,choix_2) == 2){
					printf("Egalite!\n\n");
				}
			}
		}
		//
		printf("\nVoici le score: %s: %d et %s: %d\n\n\n",pseudo_1,pts_1,pseudo_2,pts_2 );
		do{
			printf("Voulez vous rejouer? oui ou non\n\n");
			printf("Saisir oui ou non:  ");
            fflush(stdin);
            scanf("%s",choix);
            if(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0){
                printf("\nErreur de saisie\n\n");
            }

        }while(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0);
            system("PAUSE");
            system("CLS");
	}while(strcmp(choix,"oui") == 0);

	return;
}
