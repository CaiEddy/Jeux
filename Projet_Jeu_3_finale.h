#ifndef PROJET_JEU_3_FINALE_H_INCLUDED
#define PROJET_JEU_3_FINALE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAILLE_3 3
#define TAILLE_4 4
#define MAX_GAME 4

int selection_3_ou_4();
int who_start(char * p1, char * p2);
void allocation(int ** tableau, int taille);
void initialisation(int ** tableau, int taille);
void affichage_jeu(int ** tableau, int taille);
void request_placement(char * p, int ** tableau, int obj, int taille);
int game_egalite(int ** tableau, int taille);
void resultat(char * p1, char * p2, int pts_1, int pts_2);
void play(char * p1, char * p2, int ** tableau, int taille, int first);
int win_condition_3x3(int ** tableau, int first);
int win_condition_4x4(int ** tableau, int first);
void jeu(char * p1, char * p2, int ** tableau, int select);
void jeu_3(char * pseudo_1, char * pseudo_2);


#endif // PROJET_JEU_3_FINALE_H_INCLUDED
