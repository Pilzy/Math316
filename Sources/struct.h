
#ifndef MAIN
#define MAIN

/*Inclusion des librairies*/
#include <stdio.h>
#include <stdlib.h>

/*Define demandés*/
#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||

/*Structures*/
typedef enum
{
	false,
	true
} bool;

typedef struct tmp_image
{
	bool toutnoir ;
	struct tmp_image * fils[4] ;
} r_image, *image ;

/*Prototypes*/
image construit_blanc();
image construit_noir();
image construit_composee(image, image, image, image);
image lireClavier();
void affichageNormal(image);
void affichageProfondeur(image);
void affichage2k(image);
bool estBlanche(image);
bool estNoire(image);
bool memeDessin(image, image);
image simplifie(image);
image copie(image);
image negatif(image);
image difference(image, image);
int aireNoire(image);
void rendMemoire(image);
image arrondie(image, int);
image nebuleuse(int);
image alea(int, int);

#endif
