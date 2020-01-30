
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              UVa 12942 - Sub-expression Counting              *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

#define ALPHA 0
#define BETA 1
#define EXPALPHA 2
#define EXPBETA 3

#define PA '0'
#define PC '1'
#define NV '2'
#define OP '3'
#define TAM 400010

int F[TAM];
char A[4][TAM];

void Tabla(const char *P, int *R, int n){

	int i= 0, j= -1; 
	R[0]= j;

	while(i<n){

		while(j >= 0 && P[i] != P[j])
			j= R[j];
		++i;
		++j;
		R[i]= j;

	}

}

int KMP(const char *P, const char *T, const int *R, int n, int m){

	int i= 0, j= 0, cont= 0;

	while(i<m){

		while(j >= 0 && P[j] != T[i])
			j= R[j];
		++i;
		++j;

		if(j==n)
			++cont;

	}

	return cont;

}

int main(){

	int tf[4], rest;
	
	while(scanf("%s %s", A[ALPHA], A[BETA]) != EOF){

		tf[ALPHA]= strlen(A[ALPHA]);
		tf[BETA]= strlen(A[BETA]);

		for(int k= 0; k<2; ++k){
			tf[k+2]= 0;
			for(int i= 0; i<tf[k]; ++i)
				if(A[k][i] == '(')
					A[k+2][tf[k+2]++]= PA;
				else
					if(A[k][i] == ')')
						A[k+2][tf[k+2]++]= PC;
					else
						if(isalnum(A[k][i])){
							while(i+1<tf[k] && isalnum(A[k][i+1]))
								++i;
							A[k+2][tf[k+2]++]= NV;
						}else
							A[k+2][tf[k+2]++]= OP;

			A[k+2][tf[k+2]]= '\0';
		}

		Tabla(A[EXPALPHA], F, tf[EXPALPHA]);
		rest= KMP(A[EXPALPHA], A[EXPBETA], F, tf[EXPALPHA], tf[EXPBETA]);

		printf("%d\n", rest);

	}

	return 0;
}