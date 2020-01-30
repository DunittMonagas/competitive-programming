
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*             UVa 11991 - Easy Problem from Rujia Liu?          *
*****************************************************************
*/

#include <cstdio>
#include <vector>

using namespace std;

#define TAM 1000010

typedef vector<int> vi;

int main(){

	int n, m, aux;

	while(scanf("%d %d", &n, &m) != EOF){

		vector<vi> A;
		A.reserve(TAM);

		for(int i= 1; i<=n; ++i){
			scanf("%d", &aux);
			A[aux].push_back(i);
		}

		for(int i= 0; i<m; ++i){
			scanf("%d %d", &n, &aux);

			(A[aux].size() < n ? printf("0\n") : printf("%d\n", A[aux][n-1]));
		
		}

	}


	return 0;
}