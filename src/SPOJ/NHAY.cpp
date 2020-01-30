
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*               SPOJ NHAY - A Needle in the Haystack            *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

#define TAM 5000000

int R[TAM];
char P[TAM], T[TAM];

void Tabla(int n){

	int i= 0, j= -1;
	R[0]= j;

	while(i < n){

		while(j >= 0 && P[i] != P[j])
			j= R[j];

		++i;
		++j;
		R[i]= j;

	}

}

bool KMP(int n, int m){

	bool e= false;
	int i= 0, j= 0;

	while(i < m){

		while(j >= 0 && P[j] != T[i])
			j= R[j];

		++i;
		++j;

		if(j == n){
			e= true;
			printf("%d\n", i - j);
		}

	}

	printf("\n");

	return e;

} 

int main(){

	bool ln;
	int n, m;

	while(scanf("%d\n", &n) != EOF){
		scanf("%s", P);
		scanf("%s", T);

		ln= true;
		m= strlen(T);

		Tabla(n);
		ln= KMP(n, m);

		if(!n)
			printf("\n");

	}

	return 0;
}