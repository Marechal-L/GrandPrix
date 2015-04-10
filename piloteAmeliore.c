
#include "fonctions.h"


 // Pour le débuggage

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int dansSable)
{
	int valeur = accX*accX + accY*accY;
	valeur += (int)(sqrt(velX*velX+velY*velY)*3.0/2.0);
	if (dansSable) valeur += 1;
	return -valeur;
}

int main(int argn, char** argv)
{
	char c;
	int i, carburant = 0;
	
	info = fopen("PiloteAmeliore.log","w"); // Pour le débuggage

	printf("info : %p",info);
	Map *map = map_charger();
	fprintf(info,"\n === Debut Course === \n");
	int tour = 0;
	int accX = 0, accY = -1;
	int velX = 0, velY = 0;
	char action[100];
	while(!feof(stdin))
	{
		tour++;
		fprintf(info,"\n === Tour %d === \n", tour);
		
		//Écriture de l'accélération.
		sprintf(action,"%d %d",accX,accY);
		fprintf(stdout, "%s\n", action);
		fflush(stdout); // Vidage du buffer nécessaire.
		fflush(info);
	}


	return EXIT_SUCCESS;
} 
