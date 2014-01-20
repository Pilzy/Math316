
/* Contient les fonctonnalités de lecture en entrée pour création d'image */

#include "struct.h"


/* Lit une entrée sur la ligne de commande tant que la lettre Q n'a pas été trouvée.
   Si la lettre Q est trouvée alors l'image est complétée avec du blanc. */

image lireClavier()
{
	char c;
	
	printf("Entrez votre image au format normal et tapez q pour arrêter votre entrée");
	
	/* On trouve sur l'entree un caractere acceptable */
	for(c = getchar(); (c != 'q') && (c != 'Q') && (c != 'B') && (c != 'N') && (c != '.'); c = getchar());
	
	if((c == 'q') || (c == 'Q'))
		return NULL;
	else
		return lireClavierRecurssif(c);
}

image lireClavierRecurssif(char c)
{
	int i;
	char tmp[4];
	
	if(c == 'B')
		return construitBlanc();
	else if(c == 'N')
		return construitNoir();
	else if(c == '.')
	{
		/* On recupere les 4 caracteres elligibles suivant */
		for(i = 0; i < 4; i++)
		{
			for(tmp[i] = getchar(); (tmp[i] != 'q') && (tmp[i] != 'Q') && (tmp[i] != 'B') && (tmp[i] != 'N') && (tmp[i] != '.'); tmp[i] = getchar());
			
			/* Si on dit de quitter au milieu de la defition de l'image on la complete avec du blanc. */
			if((c == 'q') || (c == 'Q'))
			{
				for(;i < 4; tmp[i] = 'B', i++);
				break;
			}
		}
		
		/* On construit la sous-image */
		return construitComposee(lireClavierRecurssif(tmp[0]), lireClavierRecurssif(tmp[1]), lireClavierRecurssif(tmp[2]), lireClavierRecurssif(tmp[3]));
	}
}

