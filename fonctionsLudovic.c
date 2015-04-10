#include "fonctionsLudovic.h"

Jeu* jeu_creer()
{
	Jeu *jeu = NULL;
	
	errno=0;
	jeu = (Jeu*)malloc(1*sizeof(Jeu));
	GESTION_ERREUR(jeu,NULL);

	jeu->map = map_charger();

	jeu->nbrBoost = 5;

	return jeu;
}

Map* map_creer(int tailleX, int tailleY)
{
	int i;
	Map *map = NULL;
	
	errno=0;
	map = (Map*)calloc(1,sizeof(Map));
	GESTION_ERREUR(map,NULL);
	
	errno=0;
	map->matrice = (char**) calloc(tailleY,sizeof(Map*));
	GESTION_ERREUR(map->matrice,NULL);

	for(i=0;i<tailleY;i++)
	{
		errno=0;
		map->matrice[i] = (char*) calloc(tailleX,sizeof(Map));
		GESTION_ERREUR(map->matrice,NULL);
	}

	map->tailleX = tailleX;
	map->tailleY = tailleY;
	map->carburant = 0;
	
	return map;
}

Map* map_charger()
{
	Map *map = NULL;
	int tailleX, tailleY, carburant, i, j=0;
	char c;

	fscanf(stdin,"%d %d %d", &tailleX, &tailleY, &carburant);
	map = map_creer(tailleX, tailleY);

	while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n');
	for (i=0; i<tailleY; i++) 
	{
		j=0;
		while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n')
		{
			map->matrice[i][j] = c;
			j++;
		}
	}
	return map;
}

void map_afficher(Map *map)
{
	fprintf("<=== Carte ===>\n");
	for(i=0;i<jeu->map->tailleY;i++)
	{
		for(j=0;j<jeu->map->tailleX;j++)
		{
			fprintf(info,"%c",jeu->map->matrice[i][j]);
		}
		fprintf(info,"\n");
	}
	fflush(info);
}

