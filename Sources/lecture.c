
/* Contient les fonctonnalités de lecture en entrée pour création d'image */

#include "struct.h"


/* Lit une image écrite en mode normal sur la ligne de commande.
   Ignore les caracteres autre que B, N ou . et ne prend pas en compte les caractères en trop. */
image lireClavier()
{
	char c;
	image resultat = NULL;
	
	printf("Entrez votre image au format normal :\n");
	
	/* On trouve sur l'entree un caractere acceptable (soit B, N ou .) */
	for(c = getchar(); (c != 'B') && (c != 'N') && (c != '.'); c = getchar());
	
	/* On appelle la fonction récrusive de lecture */
	resultat = lireClavierRecurssif(c);
	viderBuffer();
	return resultat;
}

image lireClavierRecurssif(char c)
{
	int i;
	char ctmp;
	image tmp[4];
	image resultat;
	
	/* Si on a un B => image blanche */
	if(c == 'B')
		resultat = construitBlanc();
	/* Si on a un N => image noire */
	else if(c == 'N')
		resultat = construitNoir();
	/* Si on a un . => on pixellise */
	else if(c == '.')
	{
		/* On recupere les images suivantes */
		for(i = 0; i < 4; i++)
		{
			/* On trouve sur l'entree un caractere acceptable (soit B, N ou .) */
			for(ctmp = getchar(); (ctmp != 'B') && (ctmp != 'N') && (ctmp != '.'); ctmp = getchar());
			
			/* On appelle la fonction récrusive de lecture */
			tmp[i] = lireClavierRecurssif(ctmp);
		}
		
		/* On construit l'image pixelllisée à partir des pixels récupérés. */
		resultat = construitComposee(tmp[0], tmp[1], tmp[2], tmp[3]);
	}
	
	return resultat;
}

void viderBuffer()
{
	int c = 0;
	
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}
