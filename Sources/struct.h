
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
image construitBlanc();
image construitNoir();
image construitComposee(image, image, image, image);
image lireClavier();
image lireClavierRecurssif(char);
void affichageNormal(image);
void affichageProfondeur(image);
void affichageProfondeurK(image, int);
void affichage2k(image, int);
void affichage2kRecursif(image, int);
void affichage2kHaut(image, int);
void affichage2kBas(image, int);
bool estBlanche(image);
bool estNoire(image);
bool memeDessin(image, image);
void simplifie(image*);
image copie(image);
void negatif(image*);
image difference(image, image);
double aireNoire(image);
double aireNoireRecursif(image, int);
void rendMemoire(image);
image arrondie(image, int);
image nebuleuse(int);
image alea(int, int);
void viderBuffer();
bool memeImage(image, image);
int profondeur(image img);

/* Prototypes des tests */
void testFonctionsDeBase();

#endif
