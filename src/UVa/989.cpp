
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 989 - Su Doku                        *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

using namespace std;

#define CAJA(f, c, n) ((f/n)*n + c/n)

bool l, s;
int n, n2;
int T[10][10];
bool F[10][10], C[10][10], S[10][10];

bool Funcion(int f, int c, int i){

	if(i >= n2*n2)
		return true;

	if(T[f][c])
		return Funcion((i+1)/n2, (i+1)%n2, i+1);

	for(int k= 1; k<=n2; ++k)
		if(!F[f][k] && !C[c][k] && !S[CAJA(f, c, n)][k]){

			T[f][c]= k;
			F[f][k]= C[c][k]= S[CAJA(f, c, n)][k]= true;

			if(Funcion((i+1)/n2, (i+1)%n2, i+1))
				return true;

			F[f][k]= C[c][k]= S[CAJA(f, c, n)][k]= false;
			T[f][c]= 0;

		}

	return false;
}

int main(){

	while(scanf("%d", &n) != EOF){

		s= true;
		n2= n*n;

		for(int i= 0; i<n2; ++i)
			for(int j= 0; j<n2; ++j){

				scanf("%d", &T[i][j]);

				if(s && T[i][j]){
					if(F[i][T[i][j]] || C[j][T[i][j]] || S[CAJA(i, j, n)][T[i][j]])
						s= false;
						
					F[i][T[i][j]]= C[j][T[i][j]]= S[CAJA(i, j, n)][T[i][j]]= true;

				}

			}

		if(l)
			printf("\n");

		if(n == 1)
			printf("1\n");
		else
			if(s && Funcion(0, 0, 0))
				for(int i= 0; i<n2; ++i){
					for(int j= 0; j<n2; ++j)
						(j+1 != n2 ? printf("%d ", T[i][j]) : printf("%d", T[i][j]));
					printf("\n");
				}
			else
				printf("NO SOLUTION\n");

		l= true;
		memset(F, 0, 100);
		memset(C, 0, 100);
		memset(S, 0, 100);

	}

	return 0;
}