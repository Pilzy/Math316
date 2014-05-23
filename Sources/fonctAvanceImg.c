
/* Contient les fonctonnalités un peu plus avancées. */

#include "struct.h"
#include <time.h>
#include <math.h>


void arrondie(image* img, int k)
{
	/* Si l'image n'est ni blanche ni noire à ce niveau */
	if(*img != NULL && !((*img)->toutnoir))
	{
		/* Si on doit arrondir */
		if(k == 0)
		{
			/*Si l'image n'est ni blanche ni noire nous arrondissons en dessous */
			if(!estBlanche((*img)->fils[0]) && !estNoire((*img)->fils[0]))
				arrondie(&((*img)->fils[0]), k);
			/*Si l'image n'est ni blanche ni noire nous arrondissons en dessous */
			if(!estBlanche((*img)->fils[1]) && !estNoire((*img)->fils[1]))
				arrondie(&((*img)->fils[1]), k);
			/*Si l'image n'est ni blanche ni noire nous arrondissons en dessous */
			if(!estBlanche((*img)->fils[2]) && !estNoire((*img)->fils[2]))
				arrondie(&((*img)->fils[2]), k);
			/*Si l'image n'est ni blanche ni noire nous arrondissons en dessous */
			if(!estBlanche((*img)->fils[3]) && !estNoire((*img)->fils[3]))
				arrondie(&((*img)->fils[3]), k);
			
			/* L'arrondi en lui-même. Dans le cas où il y a autant de blanc que de noir le noir l'emporte. */
			/* 0 = B, 1 = ?, 2 = ?, 3 = ?. */
			if(estBlanche((*img)->fils[0]))
			{
				/* 0 = B, 1 = B, 2 = ?, 3 = ?. */
				if(estBlanche((*img)->fils[1]))
				{
					/* 0 = B, 1 = B, 2 = B, 3 = ?. */
					/* Il y a 3 B on arrondit B. */
					if(estBlanche((*img)->fils[2]))
					{
						rendMemoire(*img);
						*img = construitBlanc();
					}
					/* 0 = B, 1 = B, 2 = N, 3 = ?. */
					else
					{
						/* 0 = B, 1 = B, 2 = N, 3 = B. */
						/* Il y a 3 B on arrondit B. */
						if(estBlanche((*img)->fils[3]))
						{
							rendMemoire(*img);
							*img = construitBlanc();
						}
						/* 0 = B, 1 = B, 2 = N, 3 = N. */
						/* Il y a 2 N on arrondit N. */
						else
						{
							rendMemoire(*img);
							*img = construitNoir();
						}
					}
				}
				/* 0 = B, 1 = N, 2 = ?, 3 = ?. */
				else
				{
					/* 0 = B, 1 = N, 2 = B, 3 = ?. */
					if(estBlanche((*img)->fils[2]))
					{
						/* 0 = B, 1 = N, 2 = B, 3 = B. */
						/* Il y a 3 B on arrondit B. */
						if(estBlanche((*img)->fils[3]))
						{
							rendMemoire(*img);
							*img = construitBlanc();
						}
						/* 0 = B, 1 = N, 2 = B, 3 = N. */
						/* Il y a 2 N on arrondit N. */
						else
						{
							rendMemoire(*img);
							*img = construitNoir();
						}
					}
					/* 0 = B, 1 = N, 2 = N, 3 = ?. */
					/* Il y a 2 N on arrondit N. */
					else
					{
						rendMemoire(*img);
						*img = construitNoir();
					}
				}
			}
			/* 0 = N, 1 = ?, 2 = ?, 3 = ?. */
			else
			{
				/* 0 = N, 1 = B, 2 = ?, 3 = ?. */
				if(estBlanche((*img)->fils[1]))
				{
					/* 0 = N, 1 = B, 2 = B, 3 = ?. */
					if(estBlanche((*img)->fils[2]))
					{
						/* 0 = N, 1 = B, 2 = B, 3 = B. */
						/* Il y a 3 B on arrondit B. */
						if(estBlanche((*img)->fils[3]))
						{
							rendMemoire(*img);
							*img = construitBlanc();
						}
						/* 0 = N, 1 = B, 2 = B, 3 = N. */
						/* Il y a 2 N on arrondit N. */
						else
						{
							rendMemoire(*img);
							*img = construitNoir();
						}
					}
					/* 0 = N, 1 = B, 2 = N, 3 = ?. */
					/* Il y a 2 N on arrondit N. */
					else
					{
						rendMemoire(*img);
						*img = construitNoir();
					}
				}
				/* 0 = N, 1 = N, 2 = ?, 3 = ?. */
				/* Il y a 2 N on arrondit N. */
				else
				{
					rendMemoire(*img);
					*img = construitNoir();
				}
			}
		}
		/* Sinon on appelle la fonction récursivement pour qu'elle arrondisse les pixels du dessous */
		else 
		{
			arrondie(&((*img)->fils[0]), k - 1);
			arrondie(&((*img)->fils[1]), k - 1);
			arrondie(&((*img)->fils[2]), k - 1);
			arrondie(&((*img)->fils[3]), k - 1);
		}
	}
}

image nebuleuse(int k)
{
	srand(time(NULL));
	int i, j, r, d, dG, tmp = pow(2, k);
	char** matrice = NULL;
	image imgResult = NULL;
	
	/*Allocation de la matrice*/
	matrice = (char**) calloc(tmp, sizeof(char*));
	for(i = 0; i < tmp; matrice[i] = (char*) calloc(tmp, sizeof(char)), i++);
	
	dG = tmp / sqrt(2);
	
	/* On ajoute les points à la matrice */
	for(i = 0; i < tmp; i++)
	{
		for(j = 0; j < tmp; j++)
		{
			r = rand() % 100;
			d = sqrt((i - tmp / 2) * (i - tmp / 2) + (j - tmp / 2) * (j - tmp / 2));
			
			if(r < (dG - d) * 100 / dG)
				matrice[i][j] = '8';
			else
				matrice[i][j] = '.';
		}
	}
	
	/* On récupère notre image. */
	imgResult = matriceToImage(k, matrice, 0, 0);
	
	/* On libère la matrice. */
	for(i = 0; i < tmp; free(matrice[i]), i++);
	free(matrice);
	
	return imgResult;
}

image alea(int k, int nOrigin)
{
	srand(time(NULL));
	int i, j, l, tmp = pow(2, k), r, n;
	char** matrice = NULL;
	image imgResult = NULL;
	
	if(nOrigin > tmp * tmp)
		n = tmp * tmp;
	else if(nOrigin >= (tmp * tmp) / 2)
		n = tmp * tmp - nOrigin;
	else
		n = nOrigin;
	
	/*Allocation de la matrice*/
	matrice = (char**) calloc(tmp, sizeof(char*));
	for(i = 0; i < tmp; matrice[i] = (char*) calloc(tmp, sizeof(char)), i++);
	
	/* Remplissage de la matrice en blanc */
	for(i = 0; i < tmp; i++)
	{
		for(j = 0; j < tmp; j++)
		{
			if(nOrigin < (tmp * tmp) / 2)
				matrice[i][j] = '.';
			else
				matrice[i][j] = '8';
		}
	}
	
	if(n == 0 || n == tmp * tmp)
		return matriceToImage(k, matrice, 0, 0);
	
	/* On ajoute les points noirs à la matrice */
	for(i = 0; i < n; i++)
	{
		r = (rand()%(tmp * tmp - i)) + 1;
		
		j = r % tmp;
		l = (r - j) / tmp;
		
		/* Tant qu'on n'a pas trouvé un endroit blanc situé après r */
		while(((nOrigin < (tmp * tmp) / 2) && (matrice[l][j] != '.')) || ((nOrigin >= (tmp * tmp) / 2) && (matrice[l][j] != '8')))
		{
			if(j + 1 < tmp)
				j++;
			else
			{
				j = 0;
				l++;
			}
			
			if(l == tmp)
			{
				fprintf(stderr, "La fonction alea n'a pas trouvé d'emplacement vide situé après %d pour le colorer en noir.\n", r);
				return NULL;
			}
		}
		
		if(nOrigin < (tmp * tmp) / 2)
			matrice[l][j] = '8';
		else
			matrice[l][j] = '.';
	}
	
	/* On récupère notre image. */
	imgResult = matriceToImage(k, matrice, 0, 0);
	
	/* On libère la matrice. */
	for(i = 0; i < tmp; free(matrice[i]), i++);
	free(matrice);
	
	return imgResult;
}

image matriceToImage(int k, char** matrice, int ligneDebut, int colonneDebut)
{
	int i, j, tmp;
	bool toutBlanc = true, toutNoir = true;
	image img1, img2, img3, img4;
	
	tmp = pow(2, k);
	/* On regarde si l'image a traiter est entierement blanche ou entierement noire */
	for(i = ligneDebut; i < ligneDebut + tmp; i++)
	{
		for(j = colonneDebut; j < colonneDebut + tmp; j++)
		{
			if(matrice[i][j] == '.')
				toutNoir = false;
			else if(matrice[i][j] == '8')
				toutBlanc = false;
			else if(matrice[i][j] == '-')
			{
				toutBlanc = false;
				toutNoir = false;
			}
			else
			{
				fprintf(stderr, "Caractere non attendue dans la matrice utilisee par la fonction matriceToImage()\n");
				return NULL;
			}
			
			if(!toutBlanc && !toutNoir)
				break;
		}
		
		if(!toutBlanc && !toutNoir)
			break;
	}
	
	if(toutBlanc)
		return construitBlanc();
	else if(toutNoir)
		return construitNoir();
	else if(k != 0)
	{
		tmp = pow(2, k - 1);
		img1 = matriceToImage(k - 1, matrice, ligneDebut, colonneDebut);
		img2 = matriceToImage(k - 1, matrice, ligneDebut, colonneDebut + tmp);
		img3 = matriceToImage(k - 1, matrice, ligneDebut + tmp, colonneDebut);
		img4 = matriceToImage(k - 1, matrice, ligneDebut + tmp, colonneDebut + tmp);
		
		return construitComposee(img1, img2, img3, img4);
	}
	/* Le cas où nous rencontrons '-' dans la matrice.
	   Nous le résolvons en crréant une image à moitié noire et à moitié blanche. */
	else
		return construitComposee(construitBlanc(), construitNoir(), construitBlanc(), construitNoir());
	
}
