
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*  	                    UVa 278 - Chess                         *
*****************************************************************
*/

#include <cstdio>

using namespace std;

#define min(x, y) ((x < y) ? (x):(y))

int main(){

	char p;
	int t, r, c, rest;

	scanf("%d\n", &t);
	while(t--){

		scanf("%c %d %d\n", &p, &r, &c);

		if(p == 'r' || p == 'Q')
			rest =	min(r, c);
		else if(p == 'k')
			rest = (r*c + 1)/2;
		else if(p == 'K')
			rest = ((r+1)/2) * ((c+1)/2);

		printf("%d\n", rest);

	}

	return 0;
}