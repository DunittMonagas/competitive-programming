
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                       UVa 441 - Lotto                         *
*****************************************************************
*/

#include <cstdio>

int A[15];

int main(){

	int k;

	scanf("%d", &k);
	while(k != 0){
		
		for(int i= 0; i<k; ++i)
			scanf("%d", &A[i]);

		for(int a= 0; a<k-5; ++a)
			for(int b= a+1; b<k-4; ++b)
				for(int c= b+1; c<k-3; ++c)
					for(int d= c+1; d<k-2; ++d)
						for(int e= d+1; e<k-1; ++e)
							for(int f= e+1; f<k; ++f)
								printf("%d %d %d %d %d %d\n", A[a], A[b], A[c], A[d], A[e], A[f]);

		scanf("%d", &k);

		if(k != 0)
			printf("\n");
	}

	return 0;
}