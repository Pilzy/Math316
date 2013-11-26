
#include "main.h"

/*Pour compiler dans un terminal : make*/
/*
	git commit -a
	git pull origin master
	git push
*/

int main()
{
	printf("Pour une fois c'est moi qui baise ta soeur ;) \n");
	
	return 0;
}

image construit_blanc()
{
	image p;
	p->toutnoir=false;
	return p;
}

image construit_noir()
{
	image p;
	p->toutnoir=true;
	return p;
}

void construit_composee(image i1, image i2, image i3, image i4)
{
	image p;
	p->fils[1]=i1;
	p->fils[2]=i2;
	p->fils[3]=i3;
	p->fils[4]=i4;
}
