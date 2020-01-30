
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 10300 - Ecological Premium                *
*****************************************************************
*/

#include <cstdio>

int main(){

	int t, g;
	long long int tam, an, eco, r;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		r= 0;
		scanf("%d", &g);
		for (int j = 0; j<g; ++j){

			scanf("%lld %lld %lld", &tam, &an, &eco);
			r+= tam*eco;

		}

		printf("%lld\n", r);

	}

	return 0;
}