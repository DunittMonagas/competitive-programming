
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*               UVa 750 - 8 Queens Chess Problem                *
*****************************************************************
*/

#include <cstdio>
#include <bitset>
#include <cstring>

using namespace std;

#define TAM 8

bitset<20> fi, di, dd;
int cont, sol[10], a, b;

void bactrack(int c){

	if(c == TAM && sol[b] == a){
		printf("%2d     ", ++cont);
		for(int i= 0; i<TAM; ++i)
			printf(" %d", sol[i] + 1);
		printf("\n");
	}else
		for(int r= 0; r<TAM; ++r)
			if(!fi[r] && !di[r - c + TAM - 1] && !dd[r + c]){
				sol[c]= r;
				fi[r]= di[r - c + TAM - 1]= dd[r + c]= true;
				bactrack(c+1);
				fi[r]= di[r - c + TAM - 1]= dd[r + c]= false;
				sol[c]= 0;
			}

}

int main(){


	int t;
	scanf("%d", &t);

	while(t--){

		scanf("%d %d", &a, &b);
		--a;
		--b;

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		cont= 0;
		bactrack(0);
		memset(sol, 0, sizeof(sol));

		if(t)
			printf("\n");

	}
	return 0;
}