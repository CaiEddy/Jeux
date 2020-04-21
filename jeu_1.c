#include "Projet_Jeu_1_finale.h"

	// MOT 											| INDICE
	// si vous voulez rajouter un autre mot_X 		| si ajout de mot alors
	// ajouter une autre variable (mot_X[]=...) 	| ajouter les 4 indicies liees au mot
	// ajouter un strcpy(mot_a_deviner_[X], mot_X)	|
	// changer NB_MOTS								|
	char mot_0[] = "gold" ; 	    char indice_0_0[] = "physicien" ; char indice_0_1[] = "depute" ; char indice_0_2[] = "long nez" ; char indice_0_3[] = "juif" ;
	char mot_1[] = "suite" ; 	    char indice_1_0[] = "arithmetique" ; char indice_1_1[] = "geometrique" ; char indice_1_2[] = "adjacente" ; char indice_1_3[] = "arithemetico-geometrique" ;
	char mot_2[] = "tdur" ; 		char indice_2_0[] = "bien vu" ; char indice_2_1[] = "t'es un bon" ; char indice_2_2[] = "bien joue" ; char indice_2_3[] = "cimer" ;
	char mot_3[] = "sacha" ; 		char indice_3_0[] = "ketchum" ; char indice_3_1[] = "le meme age toute sa vie" ; char indice_3_2[] = "bourg-palette" ; char indice_3_3[] = "toujours une casquette" ;
	char mot_4[] = "arc" ; 			char indice_4_0[] = "Katniss (hunger games)" ; char indice_4_1[] = "cupidon" ; char indice_4_2[] = "cercle" ; char indice_4_3[] = "triomphe" ;


void allocation_mots(char ** tableau){
	for(int i=0 ; i < NB_MOTS ; i++){
		tableau[i] = (char *) malloc(TAILLE_MAX_MOT * sizeof(char));
	}
}

void allocation_tab_tab_indice(char *** tableau){
	for(int i=0 ; i < NB_MOTS ; i++){
		tableau[i] = (char **) malloc(NB_INDICE * sizeof(char *));
		for(int j=0 ; j < NB_INDICE ; j++){
			tableau[i][j] = (char *) malloc(TAILLE_MAX_INDICE * sizeof(char));
		}
	}
}

void shuffle(char **tableau, int taille){
	int j;
	char * tmp;
	if(taille == 1){
		return;
	}
	for(int i=0 ; i < taille-1 ; i++){
		// j random entre i et taille - i (inclus)
		j = i +rand()%(taille-i);
		// echange de valeur de tab[i] et tab[j]
		tmp = tableau[i];
		tableau[i] = tableau[j];
		tableau[j] = tmp;
	}
}

void jeu_1(char * pseudo){
    printf("========================================= LE MOT MYSTERE =========================================\n\n");
	// affichage regle
	printf("Bienvenue %s\n\n",pseudo);
    printf("REGLES DU JEU\n\n");
    printf("Le but du jeu est simple. Il s'agit de deviner 5 mots a la suite a l'aide d'indices.\n");
    printf("Attention, vous commencez la partie avec 20 points et a chaque erreur, vous perdez 5 points.\n");
    printf("Ecrivez les mots UNIQUEMENT en minuscule ET SANS ESPACE!\n\n\n");
    printf("Bon jeu! Have fun!\n\n\n");
    system("PAUSE");
    system("CLS");

	// MOT
	// ALLOCATION TABLEAU DE MOT
	char *mot_a_deviner[NB_MOTS]; allocation_mots(mot_a_deviner);

	// COPIE DES MOTS DANS LE TABLEAU
	mot_a_deviner[0] = mot_0;
	mot_a_deviner[1] = mot_1;
	mot_a_deviner[2] = mot_2;
	mot_a_deviner[3] = mot_3;
	mot_a_deviner[4] = mot_4;


	// INDICE
	// ALLOCATION TABLEAU DES TABLEAUX D'INDICES
	char ***tab_tab_indice;
	tab_tab_indice = (char***) malloc(NB_MOTS*sizeof(char**));
	allocation_tab_tab_indice(tab_tab_indice);

	// COPIE LES VALEUR DANS LES TABLEAUX DE TABLEAU D'INDICE
	tab_tab_indice[0][0] = indice_0_0; tab_tab_indice[0][1] = indice_0_1; tab_tab_indice[0][2] = indice_0_2; tab_tab_indice[0][3] = indice_0_3;
	tab_tab_indice[1][0] = indice_1_0; tab_tab_indice[1][1] = indice_1_1; tab_tab_indice[1][2] = indice_1_2; tab_tab_indice[1][3] = indice_1_3;
	tab_tab_indice[2][0] = indice_2_0; tab_tab_indice[2][1] = indice_2_1; tab_tab_indice[2][2] = indice_2_2; tab_tab_indice[2][3] = indice_2_3;
	tab_tab_indice[3][0] = indice_3_0; tab_tab_indice[3][1] = indice_3_1; tab_tab_indice[3][2] = indice_3_2; tab_tab_indice[3][3] = indice_3_3;
	tab_tab_indice[4][0] = indice_4_0; tab_tab_indice[4][1] = indice_4_1; tab_tab_indice[4][2] = indice_4_2; tab_tab_indice[4][3] = indice_4_3;

	char choix[100];
	do{
		int points_debut = 20; // pts debut
		int points_erreur = 5; // pts si erreur
		int points_if_perdu = 0; // pts cas si perdu
		int continuer = 1; // si on continue le jeu ou non
		int nb_mots_trouver=0; // nb mot trouver
		int points_courant = points_debut; // pts courant durant la partie
		int tableau_mot_courant[NB_MOTS] = {0,1,2,3,4}; // indices des mots courant
		char mot_user[TAILLE_MAX_MOT]; // mot que l'user choisi

		// random mot + random indice (pour eviter que ça soit toujours dans le meme ordre)
		int random;
		srand(time(NULL));
		random = rand() % NB_MOTS;
		shuffle(tab_tab_indice[random], NB_INDICE);

		do{
			// random mot + random indice (pour eviter que ça soit toujours dans le meme ordre)
			for(int i=0 ; i < NB_INDICE ; i++){
        	    printf("L'indice est: %s\n",tab_tab_indice[random][i] );
				printf("Choisir le mot: ");
				scanf("%s",mot_user);
				if(strcmp(mot_user,mot_a_deviner[random]) == 0 ){
					nb_mots_trouver = nb_mots_trouver + 1;
					if(nb_mots_trouver == NB_MOTS){
						break;
					}
					printf("\nCorrect! Passons au mot suivant!\n\n");
					break;
				}else{
					points_courant = points_courant - points_erreur;
					if(points_courant == points_if_perdu){
						continuer = 0;
						break;
					}
					printf("\nErreur. Essaye encore.\n\n");
				}
			}
			if(points_courant == points_if_perdu){
					continuer = 0;
					break;
				}
			if(nb_mots_trouver == NB_MOTS){
				break;
			}
			// quand le mot a ete trouver ou quand points = 0
			for(int i=0 ; i < NB_MOTS ; i++){
				if(tableau_mot_courant[i] == random){
					for(int j=i ; j < NB_MOTS - 1 ; j++){
						tableau_mot_courant[j] = tableau_mot_courant[j+1];
					}
				}
			}
			// pour choisir l'indice entre les mots restant
			random = rand() % (NB_MOTS - nb_mots_trouver);
			random = tableau_mot_courant[random];
			shuffle(tab_tab_indice[random], NB_INDICE);

		}while(continuer == 1);
		// affichage score
		if(nb_mots_trouver == NB_MOTS){
			printf("\nVICTOIRE avec %d mots trouves et il ne vous reste plus que %d points\n\n", nb_mots_trouver,points_courant );
		}else{
			printf("\nDEFAITE avec %d mots trouves\n\n",nb_mots_trouver);
		}
		do{
			printf("Voulez vous rejouer?\n\n");
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
