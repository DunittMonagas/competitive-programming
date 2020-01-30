
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*  	                UVa 696 - How Many Knights                  *
*****************************************************************
*/

#include <cstdio>

#define min(x, y) ((x < y) ? (x):(y))
#define max(x, y) ((x > y) ? (x):(y))

int main(){

	int r, c, rest;

	while(scanf("%d %d", &r, &c), (r || c)){

		if(r == 0 || c == 0)
			rest = 0;
		else if(r == 1 || c == 1)
			rest = max(r, c);
		else if(r == 2 || c == 2)
			rest = (max(r, c)/4)*4 + (min(2, max(r, c)%4))*2;
		else
			rest = (r*c + 1)/2;

		printf("%d knights may be placed on a %d row %d column board.\n", rest, r, c);

	}


	return 0;
}