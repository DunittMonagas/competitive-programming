
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                UVa 10496 - Collecting Beepers                 *
*****************************************************************
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define NA -1
#define INF 2000000000

int n;
int R[12][(1 << 11) + 10];
int X[12], Y[12], dist[12][12];

int F(int pos, int masc){

	if(masc == (1 << (n+1)) - 1)
		return dist[pos][0];

	if(R[pos][masc] != NA)
		return R[pos][masc];

	int aux= INF;
	for(int i= 0; i<=n; ++i)
		if(i != pos && !(masc & (1 << i)))
			aux= min(aux, dist[pos][i] + F(i, masc | (1 << i)));

	return R[pos][masc]= aux;

}

int main(){

	int t, aux;
	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &aux, &aux);
		scanf("%d %d", &X[0], &Y[0]);

		scanf("%d", &n);
		for(int i= 1; i<=n; ++i)
			scanf("%d %d", &X[i], &Y[i]);

		for(int i= 0; i<=n; ++i)
			for(int j= i+1; j<=n; ++j)
				dist[i][j]= dist[j][i]= abs(X[i] - X[j]) + abs(Y[i] - Y[j]);

		memset(R, -1, sizeof(R));
		printf("The shortest path has length %d\n", F(0, 1));

	}
	
	return 0;
}