
#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>

#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||

typedef enum
{
	false,
	true
} bool;

typedef struct tmp_image
{
	bool toutnoir ;
	struct tmp_image * fils[4] ;
} r_image;

typedef r_image *image ;

#endif
