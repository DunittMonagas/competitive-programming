
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                     UVa 11462 - Age Sort                      *
*****************************************************************
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define MIN 0
#define MAX 110
#define TAM 2000010

int A[TAM], T[MAX];

void CountingSort(int *A, int ls, int mi, int mx){

	int cont= 0;

	for(int i= 0; i<ls; ++i)
		++T[A[i] - mi];

	for(int i= mi; i<=mx; ++i)
		while(T[i-mi]){

			A[cont++]= i;
			--T[i-mi];

		}

}

int main(){

	int c, a, b;

	scanf("%d", &c);

	while(c){

		a= MAX, b= MIN;

		for (int i = 0; i<c; ++i){
			scanf("%d", &A[i]);
			a= min(a, A[i]);
			b= max(b, A[i]);
		}

		CountingSort(A, c, a, b);

		for (int i = 0; i<c; ++i)
			(i+1 != c ? printf("%d ", A[i]) : printf("%d\n", A[i]));

		scanf("%d", &c);

	}

	return 0;
}