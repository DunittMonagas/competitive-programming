
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 11858 - Frosh Week                     *
*****************************************************************
*/

#include <cstdio>

#define TAM 1000010

typedef long long LL;

LL A[TAM], T[TAM];

LL Merge(LL *A, LL *T, int In, int Med, int Fi){

	LL cont= 0;
	int i= In, j= Med+1, t= In;

	while(i <= Med && j <= Fi)
		if(A[i] <= A[j])
			T[t++]= A[i++];
		else{
			T[t++]= A[j++];
			cont+= Med-i+1;
		}
	
	while(i <= Med)
		T[t++]= A[i++];

	while(j <= Fi)
		T[t++]= A[j++];

	for (int i= In; i<=Fi; ++i)
		A[i]= T[i];
	
	return cont;

}

LL _MergeSort(LL *A,  LL *T, int In, int Fi){

	LL cont= 0;
	int Med= (In + Fi)/2;

	if(In >= Fi)
		return 0;

	return _MergeSort(A, T, In, Med) +
		   _MergeSort(A, T, Med+1, Fi) +
		   Merge(A, T, In, Med, Fi);

}

LL MergeSort(LL *A, int In, int Fi){

	return _MergeSort(A, T, In, Fi-1);
}

int main(){

	LL r;
	int n;

	while(scanf("%d", &n) != EOF){

		for(int i= 0; i<n; ++i)
			scanf("%lld", &A[i]);

		r= MergeSort(A, 0, n);

		printf("%lld\n", r);

	}

	return 0;
}