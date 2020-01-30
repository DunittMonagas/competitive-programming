
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                   Live Archive 6628 - Grachten                *
*****************************************************************
*/

#include <cstdio>

int MCD(int a, int b){
	
	while(b > 0){

		a %= b;
		a^= b;
		b^= a;
		a^= b;

	}

	return a;
}

int main(){

	int ab, bd, ac, at, d;

	while(scanf("%d %d %d", &ab, &ac, &bd) != EOF){

		d= MCD(ab*ac, bd-ac);
		printf("%d/%d\n", (ab*ac)/d, (bd-ac)/d);

	}

	return 0;
}