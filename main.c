#include <math.h>
#include <windows.h>
#include <conio.h>
#include "jeu_1.c"
#include "jeu_2.c"
#include "jeu_3.c"

int main()
{
    printf("============================= WELCOME DEAR USER =============================\n\n");

    char joueur1[100];
    char joueur2[100];
    char nb_joueur[100];
    int nombre;
    char c[100];
    do{
        printf("Nombre de joueurs (1 ou 2):  ");
        fflush(stdin);
        scanf("%s",nb_joueur);
    }while(strcmp(nb_joueur,"1") != 0 && strcmp(nb_joueur,"2") != 0);

    if(strcmp(nb_joueur,"1") == 0){
    	nombre = 1;
    }
    if(strcmp(nb_joueur,"2") == 0){
    	nombre = 2;
    }
    switch(nombre)
    {
    case 1:
        printf("\nPseudo du joueur: ");
        fflush(stdin);
        scanf("%s",joueur1);
        break;
    case 2:
        printf("\nPseudo du joueur1: ");
        fflush(stdin);
        scanf("%s",joueur1);
        printf("Pseudo du joueur2: ");
        fflush(stdin);
        scanf("%s",joueur2);
        break;
    }

    char choix[100];
    switch(nombre)
    {
    case 1:
        printf("\nPuisque vous etes seul(e) pour le moment, je vous propose de commencer par le Mot Mystere.\n");

        break;
    case 2:
        printf("\nA quel jeux souhaitez-vous jouer?\n");
        printf("\nPierre, Feuille, Puits, Ciseaux (2)\n\n");
        printf("Morpion (3)\n");
        do{
            printf("\nChoix du jeu, tappez 2 ou 3:  ");
            fflush(stdin);
            scanf("%s",choix);
            if(strcmp(choix,"2") != 0 && strcmp(choix,"3") != 0){
                printf("\nErreur de saisie\n");
            }
        }while(strcmp(choix,"2") != 0 && strcmp(choix,"3") != 0);




        break;

    }

    int tps = 5;
    printf("\nDebut du jeu dans 5 secondes\n\n");
    while(tps > 0)
    {
        printf("%2d\b\b", tps);
        Sleep(1000);
        tps--;
    }
    printf("\n\nC'est parti !!!\n\n\n");
    system("PAUSE");
    system("CLS");
    do{
        if(nombre == 1){
            system("CLS");
            jeu_1(joueur1);
            system("CLS");
            printf("Souhaitez-vous jouer a un autre jeu ?\n\n");
            do{
            printf("Saisir oui ou non:  ");
            fflush(stdin);
            scanf("%s",choix);
            if(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0){
                printf("\nErreur de saisie\n\n");
                }
            }while(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0);

            if(strcmp(choix,"oui") == 0){
                printf("\nPseudo du joueur2: ");
                fflush(stdin);
                scanf("%s",joueur2);
                printf("\nA quel jeux souhaitez-vous jouer?\n");
                printf("\nPierre, Feuille, Puits, Ciseaux (2)\n\n");
                printf("Morpion (3)\n");
                do{
                    printf("\nChoix du jeu, tappez 2 ou 3: ");
                    fflush(stdin);
                    scanf("%s",choix);
                    if(strcmp(choix,"2") != 0 && strcmp(choix,"3") != 0){
                        printf("\nErreur de saisie\n\n");
                    }
                }while(strcmp(choix,"2") != 0 && strcmp(choix,"3") != 0);
                if(strcmp(choix,"2") == 0){
                    nombre = 2;
                }
                if(strcmp(choix,"3") == 0){
                    nombre = 2;
                }
            }
            if(strcmp(choix,"non") == 0){
                printf("\n\nMerci! A bientot!\n\n" );
                return 0;
            }
        }
        if(nombre == 2){
            if(strcmp(choix,"2") == 0){
                system("CLS");
                jeu_2(joueur1,joueur2);
                system("CLS");
                printf("Souhaitez-vous jouer a un autre jeu ?\n\n");
                do{
                printf("Saisir oui ou non:  ");
                fflush(stdin);
                scanf("%s",choix);
                if(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0){
                    printf("\nErreur de saisie\n\n");
                    }
                }while(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0);

                if(strcmp(choix,"oui") == 0){
                    printf("\nA quel jeux souhaitez-vous jouer?\n");
                    printf("\nLe mot mystere (1)\n\n");
                    printf("Morpion (3)\n");
                    do{
                        printf("\nChoix du jeu, tappez 1 ou 3: ");
                        fflush(stdin);
                        scanf("%s",choix);
                        if(strcmp(choix,"1") != 0 && strcmp(choix,"3") != 0){
                            printf("\nErreur de saisie\n\n");
                        }
                    }while(strcmp(choix,"1") != 0 && strcmp(choix,"3") != 0);
                    if(strcmp(choix,"1") == 0){
                        nombre = 1;
                        printf("\nQuel joueur souhaite jouer ?\n");
                        fflush(stdin);
                        do{
                            printf("\nSaisir {1} pour %s ou {2} pour %s:  ",joueur1,joueur2);
                            fflush(stdin);
                            scanf("%s",c);
                            if(strcmp(c,"1") != 0 && strcmp(c,"2") != 0){
                                printf("\nErreur de saisie\n\n");
                            }
                        }while(strcmp(c,"1") != 0 && strcmp(c,"2") != 0);
                        if(strcmp(c,"2") == 0){
                            strcpy(joueur1,joueur2);
                        }
                    }
                    if(strcmp(choix,"3") == 0){
                        nombre = 2;
                    }
                }
                if(strcmp(choix,"non") == 0){
                    printf("\n\nMerci! A bientot!\n\n");
                    return 0;
                }
            }
            if(strcmp(choix,"3") == 0){
                system("CLS");
                jeu_3(joueur1,joueur2);
                system("CLS");
                printf("Souhaitez-vous jouer a un autre jeu ?\n\n");
                do{
                    printf("Saisir oui ou non:  ");
                    fflush(stdin);
                    scanf("%s",choix);
                    if(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0){
                        printf("\nErreur de saisie\n\n");
                        }
                }while(strcmp(choix,"oui") != 0 && strcmp(choix,"non") != 0);

                if(strcmp(choix,"oui") == 0){
                    printf("\nA quel jeux souhaitez-vous jouer?\n");
                    printf("\nLe mot mystere (1)\n\n");
                    printf("Pierre, Feuille, Puits, Ciseaux (2)\n");
                    do{
                        printf("\nChoix du jeu, tappez 1 ou 2: ");
                        fflush(stdin);
                        scanf("%s",choix);
                        if(strcmp(choix,"1") != 0 && strcmp(choix,"2") != 0){
                            printf("\nErreur de saisie\n\n");
                        }
                    }while(strcmp(choix,"1") != 0 && strcmp(choix,"2") != 0);
                    if(strcmp(choix,"1") == 0){
                        nombre = 1;
                        printf("\nQuel joueur souhaite jouer ?\n");
                        fflush(stdin);
                        do{
                            printf("\nSaisir {1} pour %s ou {2} pour %s:  ",joueur1,joueur2);
                            fflush(stdin);
                            scanf("%s",c);
                            if(strcmp(c,"1") != 0 && strcmp(c,"2") != 0){
                                printf("\nErreur de saisie\n\n");
                            }
                        }while(strcmp(c,"1") != 0 && strcmp(c,"2") != 0);
                        if(strcmp(c,"2") == 0){
                            strcpy(joueur1,joueur2);
                        }
                    }
                    if(strcmp(choix,"2") == 0){
                        nombre = 2;
                    }
                }
                if(strcmp(choix,"non") == 0){
                    printf("\n\nMerci! A bientot!\n\n");
                    return 0;
                }
            }
        }
    }while(1);

    return 0;
}
