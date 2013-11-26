
#include "main.h"

 /*Pour compiler dans un terminal : make*/
 /*
	git commit -a
	git pull origin master
	git push
 */
 
image* construit_blanc()
{
	image* p;
	p->toutnoir=false;
	return p;
}

image* construit_noir()
{
	image* p;
	p->toutnoir=true;
	return p;
}

image* construit_composee(image i1, image i2, image i3, image i4)
{
	image* p;
	p->fils[1]=i1;
	p->fils[2]=i2;
	p->fils[3]=i3;
	p->fils[4]=i4;
	return p;
}

/*void construit_image()
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

int main()
{
	printf("Pour une fois c'est moi qui baise ta soeur ;) \n");
	
	return 0;
}
