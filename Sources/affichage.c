
/* Contient les fonctonnalités d'affichage des images */

#include "struct.h"


void affichageNormal(image img)
{
	int i;
	
	if(img == NULL)
		printf("B");
	else
	{
		if(estNoire(img) == true)
			printf("N");
		else
			for(i = 0; i < 4; affichageNormal(img->fils[i]), i++);
	}
}

void affichageProfondeur(image img)
{
	int profondeur = 0, i;
	
	if(img == NULL)
		printf("B%d", profondeur);
	else
	{
		if(estNoire(img) == true)
			printf("N%d", profondeur);
		else
			for(i = 0; i < 4; affichageProfondeurK(img->fils[i], profondeur + 1), i++);
	}
}

void affichageProfondeurK(image img, int profondeur)
{
	int i;
	
	if(img == NULL)
		printf("B%d", profondeur);
	else
	{
		if(estNoire(img) == true)
			printf("N%d", profondeur);
		else
			for(i = 0; i < 4; affichageProfondeurK(img->fils[i], profondeur + 1), i++);
	}
}

void affichage2k(image img, int k)
{
	
	
}
