#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

FILE *info;

enum Case
{
	ROUTE = '#',
	ARRIVEE = '=',
	SABLE = '~'
};
typedef unsigned char Case;

typedef struct pos
{
	int x;
	int y;
}Pos;

typedef struct map
{
	int tailleX, tailleY, carburant, nbBoost;
	FILE* info;
	char **matrice;
	
}Map;

Map* map_nouveau(int tailleX, int tailleY);
void map_liberer(Map **map);

Map* map_charger();
Pos getDirectionDepart(Map *map);

#endif
