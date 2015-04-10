#include "fonctionsLudovic.h"

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int dansSable)
{
	int valeur = accX*accX + accY*accY;
	valeur += (int)(sqrt(velX*velX+velY*velY)*3.0/2.0);
	if (dansSable) valeur += 1;
	return -valeur;
}

/* Pilote de base avec lecture carburant */
int main(int argn, char** argv)
{
	info = fopen("PiloteLudovic.log","w"); // Pour le débuggage

	char c;
	int i,j;
	Jeu *jeu = NULL;

	
	jeu = jeu_creer();
	fprintf(info,"%d %d\n",jeu->map->tailleX,jeu->map->tailleY);
	
	

	fflush(info);
	fclose(info);









	fprintf(info,"\n === Debut Course === \n");
	int tour = 0;
	int accX = 0, accY = -1;
	int velX = 0, velY = 0;
	char action[100];
	int carburant = 0;

	while(!feof(stdin))
	{
		tour++;

		fprintf(info,"\n === Tour %d === \n", tour);
		//Lecture des positions.
		while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n') fprintf(info,"%c",c);
		fprintf(info,"\n === Action === \n");
		// Pas de prise en compte du sable (pas de mémorisation de la carte)
		//carburant += deltaCarburantAcceleration(accX, accY, velX, velY, 0);
		velX += accX;
		velY += accY;
		//Écriture de l'accélération.
		sprintf(action,"%d %d",accX,accY);
		fprintf(stdout, "%s\n", action);
		fprintf(info, "%s (carburant restant %d)\n", action, carburant);
		fflush(stdout); // Vidage du buffer nécessaire.
		fflush(info);

	}


	return EXIT_SUCCESS;
} 
