
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
image construit_composee(image i1, image i2, image i3, image i4);

/*void construit_image();
void construit_composee(image i1, image i2, image i3, image i4);
void est-noir(r_image A);
void est-blanche(r_image A);
void meme dessin(r_image A, r_image B);
void simplifie(r_image A);
void copie(r_image A);
void negatif(r_image A);
void difference(r_image A, r_image B);
void aire(r_image A);
void rendmemoire(r_image A);
void arrondit(r_image A);
void nebuleuse(int k);
void Alea(int k, int n);
void menu(osef);*/

#endif
