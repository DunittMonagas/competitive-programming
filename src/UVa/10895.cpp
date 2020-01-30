
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 10895 - Matrix Transpose                  *
*****************************************************************
*/

#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int A[1010], B[1010];

int main(){

	vector<vii> M;
	int f, c, n, aux, cont;

	while(scanf("%d %d", &f, &c) != EOF){
		
		M.assign(f+1, vii());

		for(int i= 1; i<=f; ++i){

			scanf("%d", &n);

			for(int k= 0; k<n; ++k)
				scanf("%d", &A[k]);

			for(int k= 0; k<n; ++k){
				scanf("%d", &aux);
				M[i].push_back(ii(A[k], aux));			
			}

		}

		printf("%d %d\n", c, f);

		for(int j= 0; j<c; ++j){

			cont= 0;
			for(int i= 1; i<=f; ++i)
				for(int k= 0; k<M[i].size(); ++k)
					if(M[i][k].first == j+1){
						A[cont]= i;
						B[cont++]= M[i][k].second;
					}	

			printf("%d", cont);
			for(int num= 0; num<cont; ++num)
				printf(" %d", A[num]);
			printf("\n");

			for(int num= 0; num<cont; ++num)
				(num+1 != cont ? printf("%d ", B[num]) : printf("%d", B[num]));
			printf("\n");

		}

	}

	return 0;
}