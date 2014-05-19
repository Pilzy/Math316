
/* Contient les fonctonnalités de base et de gestion des images */

#include "struct.h"
#include <math.h>


image construitBlanc()
{
	return NULL;
}

image construitNoir()
{
	int i;
	image img = (image) calloc(1, sizeof(r_image));
	img->toutnoir = true;
	for(i = 0; i < 4; img->fils[i] = NULL, i++);
	return img;
}

image construitComposee(image i1, image i2, image i3, image i4)
{
	image img = (image) calloc(1, sizeof(r_image));
	img->toutnoir = false;
	img->fils[0] = i1;
	img->fils[1] = i2;
	img->fils[2] = i3;
	img->fils[3] = i4;
	return img;
}

bool estBlanche(image img)
{
	if(img == NULL)
		return true;
	else if(img->toutnoir)
		return false;
	else
		return estBlanche(img->fils[0]) && estBlanche(img->fils[1]) && estBlanche(img->fils[2]) && estBlanche(img->fils[3]);
}

bool estNoire(image img)
{
	if(img == NULL)
		return false;
	else if(img->toutnoir)
		return true;
	else
		return estNoire(img->fils[0]) && estNoire(img->fils[1]) && estNoire(img->fils[2]) && estNoire(img->fils[3]);
}

bool memeDessin(image src1, image src2)
{
	if(memeImage(src1, src2))
		return true;
	else
	{
		image img2 = copie(src2);
		negatif(&img2);
		bool ret = memeImage(src1, img2);
		rendMemoire(img2);
		
		return ret;
	}
}

bool memeImage(image src1, image src2)
{
	if(src1 == NULL)
		return (src2 == NULL) ? true : false;
	else if(src2 == NULL)
		return false;
	else if(src1->toutnoir)
		return (src2->toutnoir) ? true : false;
	else if(src2->toutnoir)
		return false;
	else if(memeImage(src1->fils[0], src2->fils[0]) && memeImage(src1->fils[1], src2->fils[1]) && memeImage(src1->fils[2], src2->fils[2]) && memeImage(src1->fils[3], src2->fils[3]))
		return true;
	else
		return false;
}

/* Simplifie l'image */
void simplifie(image* img)
{
	int i;
	
	/*Si l'image est pixellisée alors on fait quelque chose. */
	if((*img) != NULL && !(*img)->toutnoir)
	{
		/* Si les 4 sont blanches alors on simplifie */
		if(estBlanche((*img)->fils[0]) && estBlanche((*img)->fils[1]) && estBlanche((*img)->fils[2]) && estBlanche((*img)->fils[3]))
		{
			/* Il faut mettre l'image a NULL donc on libère d'abord la mémoire occupée par l'image */
			rendMemoire((*img));
			
			/* L'image est définie comme blanche */
			(*img) = NULL;
		}
		/* Si les 4 sont noires alors on simplifie */
		else if(estNoire((*img)->fils[0]) && estNoire((*img)->fils[1]) && estNoire((*img)->fils[2]) && estNoire((*img)->fils[3]))
		{
			/* Il faut mettre les sous-pixels à NULL et libérer la mémoire occupée par ceux-ci */
			for(i = 0; i < 4; i++)
			{
				rendMemoire((*img)->fils[i]);
				(*img)->fils[i] = NULL;
			}
			
			/* L'image est définie comme noire */
			(*img)->toutnoir = true;
		}
		/* Sinon on essaie de simplifier les pixels */
		else
		{
			simplifie(&((*img)->fils[0]));
			simplifie(&((*img)->fils[1]));
			simplifie(&((*img)->fils[2]));
			simplifie(&((*img)->fils[3]));
		}
	}
}

/* Renvoie une image qui est la copie de celle passée en parametre */
image copie(image src)
{
	if(src == NULL)
		return construitBlanc();
	else if(src->toutnoir)
		return construitNoir();
	else
		return construitComposee(copie(src->fils[0]), copie(src->fils[1]), copie(src->fils[2]), copie(src->fils[3]));
}

/* Transforme l'image en negatif */
void negatif(image* img)
{
	int i;
	
	/* Si l'image est blanche alors on créé une image noire */
	if((*img) == NULL)
		(*img) = construitNoir();
	/* Si l'image est noire alors on libère la mémoire est on définit l'image comme étant blanche */
	else if((*img)->toutnoir)
	{
		rendMemoire(*img);
		(*img) = NULL;
	}
	/* L'image est pixellisée donc on fait le négatif des pixels */
	else
	{
		for(i = 0; i < 4; i++)
		{
			negatif(&((*img)->fils[i]));
		}
	}
}

/* Renvoie une image qui est noire là où les deux images sont différentes.
   Si une image est plus pixellisée que l'autre alors nous pixellisons l'image la moins pixellisée.
   Le résultat est simplifié au minimum pour plus de lisibilité. */
image difference(image src1, image src2)
{
	/* On commence par copier et simplifier les deux images données */
	image img1 = copie(src1);
	simplifie(&img1);
	image img2 = copie(src2);
	simplifie(&img2);
	
	/*Notre résultat */
	image resultat;
	
	/* img1 est blanche */
	if(img1 == NULL)
	{
		/* img2 est blanche */
		if(img2 == NULL)
			resultat = construitBlanc();
		/* img2 est noire */
		else if(img2->toutnoir)
			resultat = construitNoir();
		/* Il faut pixelliser img1 en faisant la différence entre les pixels */
		else
			resultat = construitComposee(difference(img1, img2->fils[0]), difference(img1, img2->fils[1]), difference(img1, img2->fils[2]), difference(img1, img2->fils[3]));
	}
	/* img1 est noire */
	else if(img1->toutnoir)
	{
		/* img2 est blanche */
		if(img2 == NULL)
			resultat = construitNoir();
		/* img2 est noire */
		else if(img2->toutnoir)
			resultat = construitBlanc();
		/* Il faut pixelliser img1 */
		else
			resultat = construitComposee(difference(img1, img2->fils[0]), difference(img1, img2->fils[1]), difference(img1, img2->fils[2]), difference(img1, img2->fils[3]));
	}
	/* img1 est pixellisée */
	else
	{
		/* img2 est blanche ou noire alors il faut la pixelliser */
		if(img2 == NULL || img2->toutnoir)
			resultat = construitComposee(difference(img1->fils[0], img2), difference(img1->fils[1], img2), difference(img1->fils[2], img2), difference(img1->fils[3], img2));
		/* Les deux images sont pixellisées */
		else
			resultat = construitComposee(difference(img1->fils[0], img2->fils[0]), difference(img1->fils[1], img2->fils[1]), difference(img1->fils[2], img2->fils[2]), difference(img1->fils[3], img2->fils[3]));
	}
	/* On rend la mémoire utilisée pour rouver le résultat */
	rendMemoire(img1);
	rendMemoire(img2);
	
	/*On simplifie le resultat avant de le retourner */
	simplifie(&resultat);
	
	return resultat;
}

double aireNoire(image img)
{
	int prof = profondeur(img);
	
	return (double) aireNoireRecursif(img, prof) / pow(2, prof * 2);
}

double aireNoireRecursif(image img, int profondeur)
{
	int i;
	double a = 0;
	
	if(img != NULL)
	{
		if(img->toutnoir)
			return pow(2, profondeur * 2);
		else
			for(i = 0; i < 4; a += aireNoireRecursif(img->fils[i], profondeur - 1), i++);
	}
	
	return a;
}

int profondeur(image img)
{
	int i, prof = 0, tmp;
	
	if(img != NULL && !img->toutnoir)
	{
		for(i = 0; i < 4; i++)
		{
			tmp = profondeur(img->fils[i]);
			if(tmp + 1 > prof)
				prof = tmp + 1;
		}
	}
	
	return prof;
}

void rendMemoire(image img)
{
	int i;
	
	if(img != NULL)
	{
		if(!img->toutnoir)
			for(i = 0; i < 4; rendMemoire(img->fils[i]), i++);
		
		free(img);
	}
}
