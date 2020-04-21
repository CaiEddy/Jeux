#ifndef PROJET_JEU_1_FINALE_H_INCLUDED
#define PROJET_JEU_1_FINALE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NB_MOTS 5
#define NB_INDICE 4
#define TAILLE_MAX_MOT 100
#define TAILLE_MAX_INDICE 100

void allocation_mots(char ** tableau);
void allocation_tab_tab_indice(char *** tableau);
void shuffle(char **tableau, int taille);
void jeu_1(char *pseudo);

#endif // PROJET_JEU_1_FINALE_H_INCLUDED
