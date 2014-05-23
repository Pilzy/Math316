
/* Contient les fonctonnalités d'affichage des images */
/* Nous n'utilisons pas forcément les fonctions estBlanche() ou estNoire()
   car elles renvoient un résultat simplifié et notre but peut être d'afficher l'image
   telle qu'elle est stockée en mémmoire (donc pixellisée si elle l'est). */

#include "struct.h"
#include <math.h>

/* Affiche l'image au format normal */
void affichageNormal(image img)
{
	int i;
	
	/* Si l'image est blanche. */
	if(img == NULL)
		printf("B");
	else
	{
		/* Si l'image est noire. */
		if(img->toutnoir)
			printf("N");
		/* Sinon on affiche les pixels */
		else
		{
			printf(".");
			for(i = 0; i < 4; affichageNormal(img->fils[i]), i++);
		}
	}
}

/* Affiche l'image au format Profondeur, elle permet de définir qu'elle est la profondeur 0 contrairement à affichageProfondeurK() */
void affichageProfondeur(image img)
{
	int profondeur = 0, i;
	
	/* Si l'image est blanche. */
	if(img == NULL)
		printf("B%d", profondeur);
	else
	{
		/* Si l'image est noire. */
		if(img->toutnoir)
			printf("N%d", profondeur);
		/* Sinon on affiche les pixels */
		else
		{
			printf(".%d", profondeur);
			for(i = 0; i < 4; affichageProfondeurK(img->fils[i], profondeur + 1), i++);
		}
	}
}

/* Affiche l'image au format Profondeur à la profondeur k et de manière récurssive */
void affichageProfondeurK(image img, int profondeur)
{
	int i;
	
	/* Si l'image est blanche. */
	if(img == NULL)
		printf("B%d", profondeur);
	else
	{
		/* Si l'image est noire. */
		if(img->toutnoir)
			printf("N%d", profondeur);
		/* Sinon on affiche les pixels */
		else
		{
			printf(".%d", profondeur);
			for(i = 0; i < 4; affichageProfondeurK(img->fils[i], profondeur + 1), i++);
		}
	}
}

/* Affiche l'image au format 2k */
void affichage2k(image img, int k)
{
	int i, j, tmp = pow(2, k);
	char** matrice = NULL;
	
	/*Allocation de la matrice*/
	matrice = (char**) calloc(tmp, sizeof(char*));
	for(i = 0; i < tmp; matrice[i] = (char*) calloc(tmp, sizeof(char)), i++);
	
	for(i = 0; i < tmp; i++)
	{
		for(j = 0; j < tmp; j++)
		{
			matrice[i][j] = '_';
		}
	}
	
	imageToMatrice(img, k, matrice, 0, 0);
	
	for(i = 0; i < tmp; i++)
	{
		for(j = 0; j < tmp; j++)
		{
			printf("%c", matrice[i][j]);
		}
		printf("\n");
	}
}

/* Créé l'image à afficher au format 2k de manière récursive. L'image est stockée dans une matrice déjà initialisée. */
void imageToMatrice(image img, int k, char** matrice, int ligneDebut, int colonneDebut)
{
	int i, j, tmp;
	
	if(estBlanche(img))
	{
		tmp = pow(2, k);
		for(i = ligneDebut; i < ligneDebut + tmp; i++)
		{
			for(j = colonneDebut; j < colonneDebut + tmp; j++)
			{
				matrice[i][j] = '.';
			}
		}
	}
	else if(estNoire(img))
	{
		tmp = pow(2, k);
		for(i = ligneDebut; i < ligneDebut + tmp; i++)
		{
			for(j = colonneDebut; j < colonneDebut + tmp; j++)
			{
				matrice[i][j] = '8';
			}
		}
	}
	else if(k == 0)
	{
		matrice[ligneDebut][colonneDebut] = '-';
	}
	else
	{
		tmp = pow(2, k - 1);
		imageToMatrice(img->fils[0], k - 1, matrice, ligneDebut, colonneDebut);
		imageToMatrice(img->fils[1], k - 1, matrice, ligneDebut, colonneDebut + tmp);
		imageToMatrice(img->fils[2], k - 1, matrice, ligneDebut + tmp, colonneDebut);
		imageToMatrice(img->fils[3], k - 1, matrice, ligneDebut + tmp, colonneDebut + tmp);
	}
}
