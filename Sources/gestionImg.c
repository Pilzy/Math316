
/* Contient les fonctonnalités de base et de gestion des images */

#include "struct.h"


image construitBlanc()
{
	return NULL;
}

image construitNoir()
{
	image img = (image) calloc(1, sizeof(r_image));
	img->toutnoir = true;
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
	return img == NULL ? true : false;
}

bool estNoire(image img)
{
	return (img != NULL) && (img->toutnoir == true) ? true : false;
}

bool memeDessin(image img1, image img2)
{
	if(img1 == NULL)
		return img2 == NULL ? true : false;
	else if(img2 == NULL)
		return false;
	
	if(img1->toutnoir == true)
		return img2->toutnoir == true ? true : false;
	else if(img2->toutnoir == true)
		return false;
	else
		return (memeDessin(img1->fils[0], img2->fils[0]) == true) && (memeDessin(img1->fils[1], img2->fils[1]) == true) && (memeDessin(img1->fils[2], img2->fils[2]) == true) && (memeDessin(img1->fils[3], img2->fils[3]) == true);
}

image simplifie(image img)
{
	image img0 = (image) calloc(1, sizeof(r_image));
	return img0;
}

/*Renvoie une image qui est la copie de celle passée en parametre */
image copie(image src)
{
	if(src == NULL)
		return NULL;
	
	image dest = (image) calloc(1, sizeof(r_image));
	
	if(src->toutnoir == true)
		dest->toutnoir = true;
	else
	{
		dest->toutnoir = false;
		dest->fils[0] = copie(src->fils[0]);
		dest->fils[1] = copie(src->fils[1]);
		dest->fils[2] = copie(src->fils[2]);
		dest->fils[3] = copie(src->fils[3]);
	}
	
	return dest;
}

/* Renvoie un negatif de l'image actuelle */
image negatif(image src)
{
	if((src != NULL) && (src->toutnoir == true))
		return NULL;
	
	image dest = (image) calloc(1, sizeof(r_image));
	
	if(src == NULL)
		dest->toutnoir = true;
	else
	{
		dest->toutnoir = false;
		dest->fils[0] = negatif(src->fils[0]);
		dest->fils[1] = negatif(src->fils[1]);
		dest->fils[2] = negatif(src->fils[2]);
		dest->fils[3] = negatif(src->fils[3]);
	}
	
	return dest;
}

/* Renvoie une image qui est noire là où les deux images sont différentes.
   Si une image est plus pixellisée que l'autre alors nous pixellisons l'image la moins pixellisée */
image difference(image img1, image img2)
{
	/* img1 est blanche */
	if(img1 == NULL)
	{
		/* img2 est blanche */
		if(img2 == NULL)
			return NULL;
		/* img2 est noire */
		else if(img2->toutnoir == true)
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = true;
			return ret;
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
			return ret;
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
			return ret;
		}
		/* img2 est noire */
		else if(img2->toutnoir == true)
			return NULL;
		/* Il faut pixelliser img1 */
		else
		{
			image ret = (image) calloc(1, sizeof(r_image));
			ret->toutnoir = false;
			ret->fils[0] = difference(img1, img2->fils[0]);
			ret->fils[1] = difference(img1, img2->fils[1]);
			ret->fils[2] = difference(img1, img2->fils[2]);
			ret->fils[3] = difference(img1, img2->fils[3]);
			return ret;
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
			return ret;
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
			return ret;
		}
	}
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

