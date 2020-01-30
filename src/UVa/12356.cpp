
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 12356 - Army Buddies                     *
*****************************************************************
*/

#include <cstdio>

#define VALID(x, ls) (x >= 1 && x <= ls)

int L[100010];
int R[100010];

int main(){

	int s, b, l, r;

	while(scanf("%d %d", &s, &b), (s || b)){

		for(int i= 0; i<=s; ++i){
			L[i]= i-1;
			R[i]= i+1;
		}

		for(int i= 0; i<b; ++i){

			scanf("%d %d", &l, &r);

			if(VALID(L[l], s)){

				R[L[l]]= R[r];
				printf("%d ", L[l]);

			}else
				printf("* ");

			if(VALID(R[r], s)){

				L[R[r]]= L[l];
				printf("%d\n", R[r]);

			}else
				printf("*\n");

		}

		printf("-\n");

	}


	return 0;

}