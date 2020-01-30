
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 11581 - Grid Successors                  *
*****************************************************************
*/

#include <cstdio>

#define VALIDAR(x, y) (x >= 0 && x < 3 && y >= 0 && y < 3)

int G[3][3];
int AdX[]= {-1, 0, 1, 0};
int AdY[]= {0, 1, 0, -1};

void F(){

	int sum, A[3][3];

	for (int f= 0; f<3; ++f)
		for (int c= 0; c<3; ++c){

			sum= 0;
			for (int i= 0; i<4; ++i)
				if(VALIDAR(f + AdX[i], c + AdY[i]))
					sum+= G[f + AdX[i]][c + AdY[i]];
				
			A[f][c]= sum%2;

		}

	for (int f= 0; f<3; ++f)
		for (int c= 0; c<3; ++c)
			G[f][c]= A[f][c];

}

bool Cero(){

	for (int f= 0; f<3; ++f)
		for (int c= 0; c<3; ++c)
			if(G[f][c])
				return false;
		
	return true;

}

int main(){

	int n, res;

	scanf("%d", &n);

	for(int t= 0; t<n; ++t){

		for(int i= 0; i<3; ++i)
			for(int j= 0; j<3; ++j)
				scanf("%1d", &G[i][j]);

		res= -1;

		while(!Cero()){

			F();
			++res;

		}

		printf("%d\n", res);

	}

	return 0;
}