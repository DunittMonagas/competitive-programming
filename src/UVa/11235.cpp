
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 11235 - Frequent values                  *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

#define TAM 200010
#define MIN -100000

typedef pair<int,int> ii;

ii F[TAM];
int A[TAM], B[TAM], C[TAM], RMQ[4*TAM];


void st_build(const int *B, int *RMQ, int vertex, int L, int R){

	if(L == R)
		RMQ[vertex]= L;
	else{

		int nL= vertex << 1;
		int nR= nL + 1;
		st_build(B, RMQ, nL, L, (L + R)/2);
		st_build(B, RMQ, nR, (L + R)/2 + 1, R);
		int lCont= RMQ[nL];
		int rCont= RMQ[nR];
		int lValue= B[lCont];
		int rValue= B[rCont];
		RMQ[vertex]= (lValue > rValue) ? lCont : rCont;

	}

}

void st_create(const int *B, int *RMQ, int n){
	st_build(B, RMQ, 1, 1, n);
}

int st_rmq(const int *B, const int *RMQ, int vertex, int L, int R, int i, int j){

	if(i > R || j < L)
		return -1;
	if(L >= i && R <= j)
		return RMQ[vertex];

	int p1= st_rmq(B, RMQ, 2*vertex, L, (L + R)/2, i, j);
	int p2= st_rmq(B, RMQ, 2*vertex+1, (L + R)/2 + 1, R, i, j);

	if(p1 == -1)
		return p2;
	if(p2 == -1)
		return p1;

	return (B[p1] > B[p2] ? p1 : p2);

}

int st_rmq(const int *B, const int *RMQ, int i, int j, int n){
	return st_rmq(B, RMQ, 1, 1, n, i, j);
}

int main(){

	int n, q, aux, aux2, i, j, r;

	while(scanf("%d %d", &n, &q) != EOF && n != 0){

		for(int t= 1; t<=n; ++t){

			scanf("%d", &aux);
			A[t]= aux;
			if(!F[aux-MIN].first)
				F[aux-MIN].second= t;
			++F[aux-MIN].first;

		}

		for(int t= 1; t<=n; ++t){
			B[t]= F[A[t]-MIN].first;
			C[t]= F[A[t]-MIN].second;
		}

		st_create(B, RMQ, n);
		
		for(int t= 0; t<q; ++t){

			scanf("%d %d", &i, &j);

			if(A[i] == A[j])
				r= j - i + 1;
			else{

				aux= (C[i] + B[i] - 1) - i + 1;
				aux2= j - C[j] + 1;
				r= max(aux, aux2);

				if((C[i] + B[i]) < (C[j] - 1)){
					aux= st_rmq(B, RMQ, C[i] + B[i], C[j] - 1, n);
					r= max(B[aux], r);
				}
			
			}

			printf("%d\n", r);

		}

		memset(F, 0, sizeof(F));

	}

	return 0;
}