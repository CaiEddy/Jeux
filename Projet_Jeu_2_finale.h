#ifndef PROJET_JEU_2_FINALE_H_INCLUDED
#define PROJET_JEU_2_FINALE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define NB_CHOIX 4
#define TAILLE_MAX_MOT 100

void allocation_mot(char ** tableau);
void choix_pour_revanche(char ** tableau, char *choix_1, char *choix_2);
void choix_pour_revanche_indice(int * tableau, int choix_1, int choix_2);
int duel_c1_vs_c2(int choix_1, int choix_2);
void affichage_bug(char *c);
void jeu_2(char * pseudo_1, char * pseudo_2);


#endif // PROJET_JEU_2_FINALE_H_INCLUDED
