
/* Contient les fonctonnalités un peu plus avancées. */

#include "struct.h"
#include <time.h>
#include <math.h>


image arrondie(image img, int k)
{
	image img0 = (image) calloc(1, sizeof(r_image));
	return img0;
}

image nebuleuse(int k)
{
	image img = (image) calloc(1, sizeof(r_image));
	return img;
}

image alea(int k, int nOrigin)
{
	srand(time(NULL));
	int i, j, l, tmp = pow(2, k), r, n;
	char** matrice = NULL;
	
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
	
	return matriceToImage(k, matrice, 0, 0);
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
