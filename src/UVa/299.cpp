
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 299 - Train Swapping                 *
*****************************************************************
*/

#include <stdio.h>

long int NUM[52];

long int Inversion(int n){
	
	long int cont= 0;

	for(int i= 0; i<n-1; ++i)
		for(int j= i+1; j<n; ++j)
			if(NUM[i] > NUM[j])
				++cont;

	return cont;
}

int main(){

	int c;
	long int n, aux, r;

	scanf("%ld", &n);

	for(long int i= 0; i<n; i++){
		
		scanf("%d", &c);

		for(int j= 0; j<c; j++)
			scanf("%ld", &NUM[j]);
	
		r= Inversion(c);

		printf("Optimal train swapping takes %ld swaps.\n", r);

	}

	return 0;
}