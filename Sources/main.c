
/*Contient le main et les tests associés. */

#include "struct.h"

/*Pour compiler dans un terminal : make*/
/*
	git commit -a
	git pull origin master
	git push
*/

int main()
{
	testFonctionsDeBase();
	
	return EXIT_SUCCESS;
}

/* Fais appel à toutes les fonctions de base contenues dans gestionImg.c, dans affichage.c et dans lecture.c */
void testFonctionsDeBase()
{
	image img1 = NULL, img2 = NULL, img3 = NULL, img4 = NULL, img5 = NULL;
	
	/* L'image 1 est lue au clavie */
	img1 = lireClavier();
	printf("\n");
	
	/* L'image 2 est copiée est mis en négatif */
	img2 = copie(img1);
	negatif(&img2);
	
	/* L'image 3 est un négatif de la 2 est doit donc être identique à la 1*/
	img3 = copie(img2);
	negatif(&img3);
	
	/* On regarde la différence entre la 1 et la 2 */
	img4 = difference(img1 , img2);
	
	/* On regarde la différence entre la 1 et la 3 */
	img5 = difference(img1 , img3);
	
	/* Affichage des résultats */
	printf("Voici votre image 1 :\n");
	affichageNormal(img1); printf("\n");
	affichageProfondeur(img1); printf("\n");
	printf("Voici votre image 2 (negatif de la 1) :\n");
	affichageNormal(img2); printf("\n");
	affichageProfondeur(img2); printf("\n");
	printf("Voici votre image 3 (negatif de la 2) :\n");
	affichageNormal(img3); printf("\n");
	affichageProfondeur(img3); printf("\n");
	printf("Voici votre image 4 (différence entre 1 et 2) :\n");
	affichageNormal(img4); printf("\n");
	affichageProfondeur(img4); printf("\n");
	printf("Voici votre image 5 (différence entre 1 et 3) :\n");
	affichageNormal(img5); printf("\n");
	affichageProfondeur(img5); printf("\n");
	printf("\n");
	
	/* Test memeDessin() */
	(memeDessin(img1, img3) == true) ? printf("La 1 et la 3 sont identiques.\n") : printf("ERREUR : La 1 et la 3 sont differentes.\n");
	printf("\n");
	
	/* Test estBlanche() et estNoire() */
	(estNoire(img4) == true) ? printf("La 4 est noire.\n") : printf("ERREUR : La 4 n'est pas noire.\n");
	(estBlanche(img5) == true) ? printf("La 5 est blanche.\n") : printf("ERREUR : La 5 n'est pas blanche.\n");
	printf("\n");
	
	/* Test aireNoire() */
	printf("Aire en noire image 1 : %d\n", aireNoire(img1));
	printf("Aire en noire image 2 : %d\n", aireNoire(img2));
	printf("Aire en noire image 3 : %d\n", aireNoire(img3));
	printf("Aire en noire image 4 : %d\n", aireNoire(img4));
	printf("Aire en noire image 5 : %d\n", aireNoire(img5));
	printf("\n");
	
	/*Affichage en mode 2k*/
	printf("Affichage en mode 2k\n");
	printf("Voici votre image 1 (Profondeur : 2) :\n");
	affichage2k(img1, 2); printf("\n");
	printf("Voici votre image 2 (Profondeur : 2) :\n");
	affichage2k(img2, 2); printf("\n");
	printf("\n");
	
	if(img1 != NULL)
		rendMemoire(img1);
	if(img2 != NULL)
		rendMemoire(img2);
	if(img3 != NULL)
		rendMemoire(img3);
	if(img4 != NULL)
		rendMemoire(img4);
	if(img5 != NULL)
		rendMemoire(img5);
	
}
