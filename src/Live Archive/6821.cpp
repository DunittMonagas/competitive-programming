
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*        Live Archive 6821 - Automated Checking Machine         *
*****************************************************************
*/

#include <cstdio>

int A[6], B[6];

int main(){

	bool f;
	while(scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4]) != EOF){
		f= true;
		for(int i= 0; i<5; ++i){
			scanf("%d", &B[i]);
			f&= A[i] ^ B[i];
		}

		(f ? printf("Y\n"):printf("N\n"));
	}

	return 0;
}