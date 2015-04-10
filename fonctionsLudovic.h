#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define GESTION_ERREUR(p, v) if(!p){ \
									fprintf(info,"Erreur : %s. \n",strerror(errno));\
									return v;}

FILE* info;

typedef struct s_position
{
	
}Position;

typedef struct s_map
{
	int tailleX, tailleY, carburant;
	char **matrice;
}Map;

typedef struct s_jeu
{
	int nbrBoost;
	Map *map;
}Jeu;

Map* map_creer(int tailleX, int tailleY);
Map* map_charger();
void map_afficher(Map *map);

Jeu* jeu_creer();


#endif //FONCTIONS_H
