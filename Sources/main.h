
#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>

#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||

typedef enum
{
	false,
	true
} bool;

typedef struct tmp_image
{
	bool toutnoir ;
	struct tmp_image * fils[4] ;
} r_image;

<<<<<<< HEAD:Test1.c
/* pour compiler dans un terminal
 gcc Test1.c -o Test1*/
 /*
 git commit -a
 git pull origin master
 git push

*/

void construit_blanc()
{
=======
typedef r_image *image ;

/*void construit_blanc()
void construit_noir()*/
void construit_composee(int, int, int, int);
>>>>>>> af5c060ba98ffdaf72b8ec67d1f4e3116307ab07:Sources/main.h

/*
void construit_noir()
void construit_composee(i1,i2,i3,i4)
void est-noir(r_image A)
void est-blanche(r_image A)
void meme dessin(r_image A, r_image B)
void simplifie(r_image A)
void copie(r_image A)
void negatif(r_image A)
void difference(r_image A, r_image B)
void aire(r_image A)
void rendmemoire(r_image A)
void arrondit(r_image A)
void nebuleuse(int k)
void Alea(int k, int n)
void menu(osef)*/

<<<<<<< HEAD:Test1.c
int main()
{
}
{
=======

#endif
>>>>>>> af5c060ba98ffdaf72b8ec67d1f4e3116307ab07:Sources/main.h
