
/* Contient les fonctonnalités d'affichage des images */
/* Nous n'utilisons pas forcément les fonctions estBlanche() ou estNoire()
   car elles renvoient un résultat simplifié et notre but peut être d'afficher l'image
   telle qu'elle est stockée en mémmoire (donc pixellisée si elle l'est). */

#include "struct.h"

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
		if(img->toutnoir == true)
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
		if(img->toutnoir == true)
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
		if(img->toutnoir == true)
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
	Image img = NULL;
	
	while(k != 0)
	{
		
	}
}

/* Affiche l'image au format 2k de manière récursive */
void affichage2kRecursif(image img, int k)
{
	int i;
	
	if(k != 0)
	{
		/* Si l'image est noire ou blanche on l'affiche 4 fois */
		if((img == NULL) || (img->toutnoir == true))
		{
			for(i = 0; i < 4; affichage2k(img, k-1), i++);
		}
		else
			for(i = 0; i < 4; affichage2k(img->fils[i], k-1), i++);
	}
	else
	{
		if(estBlanche(img))
			printf(".");
		else if(estNoire(img))
			printf("8");
		else
			printf("-");
	}
}

/* Affiche l'image au format 2k de manière récursive */
void affichage2kHaut(image img, int k)
{
	int i;
	
	if(k != 0)
	{
		/* Si l'image est noire ou blanche on l'affiche 4 fois */
		if((img == NULL) || (img->toutnoir == true))
			for(i = 0; i < 4; affichage2k(img, k-1), i++);
		else
			for(i = 0; i < 4; affichage2k(img->fils[i], k-1), i++);
	}
	else
	{
		if(estBlanche(img))
			printf(".");
		else if(estNoire(img))
			printf("8");
		else
			printf("-");
	}
}

/* Affiche l'image au format 2k de manière récursive */
void affichage2kBas(image img, int k)
{
	int i;
	
	if(k != 0)
	{
		/* Si l'image est noire ou blanche on l'affiche 4 fois */
		if((img == NULL) || (img->toutnoir == true))
			for(i = 0; i < 4; affichage2k(img, k-1), i++);
		else
			for(i = 0; i < 4; affichage2k(img->fils[i], k-1), i++);
	}
	else
	{
		if(estBlanche(img))
			printf(".");
		else if(estNoire(img))
			printf("8");
		else
			printf("-");
	}
}
