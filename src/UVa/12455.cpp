
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                       UVa 12455 - Bars                        *
*****************************************************************
*/

#include <cstdio>

using namespace std;

int A[1010];

int main() {

	int i, t, n, sum, aux;

	scanf("%d", &t);

	while(t--){

		scanf("%d %d", &sum, &n);

		for(i= 0; i<n; ++i)
			scanf("%d", &A[i]);

		for(i= 0; i < (1 << n); ++i){

			aux= 0;
			for(int j= 0; j<n; ++j)
				if(i & (1 << j))
					aux+= A[j];

			if(aux == sum)
				break;	

		}

		(i != (1 << n) ? printf("YES\n") : printf("NO\n"));

	}

	return 0;
}