
/* Contient les fonctonnalités de lecture en entrée pour création d'image */

#include "struct.h"


/* Lit une entrée sur la ligne de commande tant que la lettre Q n'a pas été trouvée.
   Si la lettre Q est trouvée alors l'image est complétée avec du blanc. */

image lireClavier()
{
	char c;
	
	printf("Entrez votre image au format normal :\n");
	
	/* On trouve sur l'entree un caractere acceptable */
	for(c = getchar(); (c != 'B') && (c != 'N') && (c != '.'); c = getchar());
	
	return lireClavierRecurssif(c);
}

image lireClavierRecurssif(char c)
{
	int i;
	char ctmp;
	image tmp[4];
	
	if(c == 'B')
		return construitBlanc();
	else if(c == 'N')
		return construitNoir();
	else if(c == '.')
	{
		/* On recupere les images suivantes */
		for(i = 0; i < 4; i++)
		{
			/* Tant qu'on n'a pas un caractere correcte */
			for(ctmp = getchar(); (ctmp != 'B') && (ctmp != 'N') && (ctmp != '.'); ctmp = getchar());
			
			tmp[i] = lireClavierRecurssif(ctmp);
		}
		
		
		/* On construit la sous-image */
		return construitComposee(tmp[0], tmp[1], tmp[2], tmp[3]);
	}
}

