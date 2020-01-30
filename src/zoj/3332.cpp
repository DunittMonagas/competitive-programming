
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 ZOJ 3332 - Strange Country II                 *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

bool Enc;
int n, R[110];
bool C[110], G[110][110];


void Calcular(int Ori, int ps){

	for(int i= 1; i<=n && !Enc; ++i){

		if(G[Ori][i] && !C[i]){

			R[++ps]= i;
			C[i]= true;

			if(ps == n){
				Enc= true;
				return;
			}

			Calcular(i, ps);

			--ps;
			C[i]= false;

		}

	}

}

void Iniciar(int Ori){

	memset(C, 0, sizeof(bool)*110);

	R[1]= Ori;
	C[Ori]= true;

	if(n!=1)
		Calcular(Ori, 1);
	else
		Enc= true;
}

int main(){

	int t, x, y;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		scanf("%d", &n);

		for(int j= 0; j<n*(n-1)/2; ++j){

			scanf("%d %d", &x, &y);
			G[x][y]= true;

		}

		for(int i= 1; i<=n && !Enc; ++i)
			Iniciar(i);
		


		if(!Enc)
			printf("Impossible\n");
		else{
			for(int i= 1; i<=n; ++i)
				if(i != n)
					printf("%d ", R[i]);
				else
					printf("%d\n", R[i]);
		}

		Enc= false;
		memset(G, 0, sizeof(bool)*12100);
		memset(C, 0, sizeof(bool)*110);


	}

	return 0;
}