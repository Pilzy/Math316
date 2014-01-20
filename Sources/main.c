
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
	image img = NULL;
	
	img = lireClavier();
	
	printf("Voici votre image : ");
	affichageNormal(img);
	printf("\n");
	affichageProfondeur(img);
	printf("\n");
	
	return 0;
}
