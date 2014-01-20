
/*Contient le main. */

#include "struct.h"

/*Pour compiler dans un terminal : make*/
/*
	git commit -a
	git pull origin master
	git push
*/

int main()
{
	image img1 = NULL, img2 = NULL, img3 = NULL;
	
	img1 = lireClavier();
	img2 = copie(img1);
	negatif(&img2);
	//img3 = difference(img1 , img2);
	
	printf("Voici votre image 1 : ");
	affichageNormal(img1);
	printf("\n");
	printf("Voici votre image 2 : ");
	affichageNormal(img2);
	printf("\n");
	printf("Voici votre image 3 : ");
	affichageNormal(img3);
	printf("\n");
	
	if(img1 != NULL)
		rendMemoire(img1);
	if(img2 != NULL)
		rendMemoire(img2);
	if(img3 != NULL)
		rendMemoire(img3);
	
	return 0;
}
