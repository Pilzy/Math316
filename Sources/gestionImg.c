
/* Contient les fonctonnalités de base et de gestion des images */

#include "struct.h"


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
	else if(img->toutnoir == true)
		return false;
	else
		return (estBlanche(img->fils[0]) == true) && (estBlanche(img->fils[1]) == true) && (estBlanche(img->fils[2]) == true) && (estBlanche(img->fils[3]) == true) ? true : false;
}

bool estNoire(image img)
{
	if(img == NULL)
		return false;
	else if(img->toutnoir == true)
		return true;
	else
		return (estNoire(img->fils[0]) == true) && (estNoire(img->fils[1]) == true) && (estNoire(img->fils[2]) == true) && (estNoire(img->fils[3]) == true) ? true : false;
}

bool memeDessin(image src1, image src2)
{
	/* On commence par simplifie les deux images données */
	image img1 = copie(src1);
	simplifie(&img1);
	image img2 = copie(src2);
	simplifie(&img2);
	
	bool ret = false;
	
	if(img1 == NULL)
		ret = img2 == NULL ? true : false;
	else if(img2 == NULL)
		ret = false;
	else if(img1->toutnoir == true)
		ret = img2->toutnoir == true ? true : false;
	else if(img2->toutnoir == true)
		ret = false;
	else
		ret = (memeDessin(img1->fils[0], img2->fils[0]) == true) && (memeDessin(img1->fils[1], img2->fils[1]) == true) && (memeDessin(img1->fils[2], img2->fils[2]) == true) && (memeDessin(img1->fils[3], img2->fils[3]) == true);
	
	rendMemoire(img1);
	rendMemoire(img2);
	
	return ret;
}

/* Simplifie l'image */
void simplifie(image* img)
{
	int i;
	
	/*Si l'image est pixellisée alors on fait quelque chose. */
	if((*img != NULL) && ((*img)->toutnoir != true))
	{
		/* Si les 4 sont blanches alors on simplifie */
		if((estBlanche((*img)->fils[0]) == true) && (estBlanche((*img)->fils[1]) == true) && (estBlanche((*img)->fils[2]) == true) && (estBlanche((*img)->fils[3]) == true))
		{
			for(i = 0; i < 4; rendMemoire((*img)->fils[i]), i++);
			rendMemoire((*img));
			(*img) = NULL;
		}
		/* Si les 4 sont noires alors on simplifie */
		else if((estNoire((*img)->fils[0]) == true) && (estNoire((*img)->fils[1]) == true) && (estNoire((*img)->fils[2]) == true) && (estNoire((*img)->fils[3]) == true))
		{
			for(i = 0; i < 4; i++)
			{
				rendMemoire((*img)->fils[i]);
				(*img)->fils[i] = NULL;
			}
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
		return NULL;
	else if(src->toutnoir == true)
		return construitNoir();
	else
		return construitComposee(copie(src->fils[0]), copie(src->fils[1]), copie(src->fils[2]), copie(src->fils[3]));
}

/* Transforme l'image en negatif */
void negatif(image* img)
{
	int i;
	image tmp = NULL;
	
	if(*img == NULL)
		*img = construitNoir();
	else if((*img)->toutnoir == true)
	{
		rendMemoire(*img);
		*img = NULL;
	}
	else
	{
		for(i = 0; i < 4; i++)
		{
			negatif(&((*img)->fils[i]));
		}
		tmp = construitComposee(copie((*img)->fils[0]), copie((*img)->fils[1]), copie((*img)->fils[2]), copie((*img)->fils[3]));
		rendMemoire(*img);
		*img = tmp;
	}
}

/* Renvoie une image qui est noire là où les deux images sont différentes.
   Si une image est plus pixellisée que l'autre alors nous pixellisons l'image la moins pixellisée */
image difference(image src1, image src2)
{
	/* On commence par simplifie les deux images données */
	image img1 = copie(src1);
	simplifie(&img1);
	image img2 = copie(src2);
	simplifie(&img2);
	
	image ret;
	
	/* img1 est blanche */
	if(img1 == NULL)
	{
		/* img2 est blanche */
		if(img2 == NULL)
			ret = NULL;
		/* img2 est noire */
		else if(img2->toutnoir == true)
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = true;
		}
		/* Il faut pixelliser img1 */
		else
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = false;
			ret->fils[0] = difference(img1, img2->fils[0]);
			ret->fils[1] = difference(img1, img2->fils[1]);
			ret->fils[2] = difference(img1, img2->fils[2]);
			ret->fils[3] = difference(img1, img2->fils[3]);
		}
	}
	/* img1 est noire */
	else if(img1->toutnoir == true)
	{
		/* img2 est blanche */
		if(img2 == NULL)
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = true;
		}
		/* img2 est noire */
		else if(img2->toutnoir == true)
			ret = NULL;
		/* Il faut pixelliser img1 */
		else
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = false;
			ret->fils[0] = difference(img1, img2->fils[0]);
			ret->fils[1] = difference(img1, img2->fils[1]);
			ret->fils[2] = difference(img1, img2->fils[2]);
			ret->fils[3] = difference(img1, img2->fils[3]);
		}
	}
	/* img1 est pixellisée */
	else
	{
		/* img2 est blanche ou blanche */
		if((img2 == NULL) || (img2->toutnoir == true))
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = false;
			ret->fils[0] = difference(img1->fils[0], img2);
			ret->fils[1] = difference(img1->fils[1], img2);
			ret->fils[2] = difference(img1->fils[2], img2);
			ret->fils[3] = difference(img1->fils[3], img2);
		}
		/* Les deux images sont pixellisées */
		else
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = false;
			ret->fils[0] = difference(img1->fils[0], img2->fils[0]);
			ret->fils[1] = difference(img1->fils[1], img2->fils[1]);
			ret->fils[2] = difference(img1->fils[2], img2->fils[2]);
			ret->fils[3] = difference(img1->fils[3], img2->fils[3]);
		}
	}
	
	rendMemoire(img1);
	rendMemoire(img2);
	
	return ret;
}

int aireNoire(image img)
{
	int a = 0, i;
	
	if(img != NULL)
	{
		if(img->toutnoir == true)
			return 1;
		else
			for(i = 0; i < 4; a += aireNoire(img->fils[i]), i++);
	}
	
	return a;
}

void rendMemoire(image img)
{
	int i;
	
	if(img != NULL)
	{
		if(img->toutnoir == false)
			for(i = 0; i < 4; rendMemoire(img->fils[i]), i++);
		
		free(img);
	}
}

