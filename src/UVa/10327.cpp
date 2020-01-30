
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                     UVa 10327 - Flip Sort                     *
*****************************************************************
*/

#include <cstdio>

typedef long long int ll;

ll A[1010], T[1010];

ll Merge(ll *A, ll *T, int In, int Med, int Fi){

	int i= In, j= Med+1, t= In, cont= 0;

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

	for (i= In; i<=Fi; ++i)
		A[i]= T[i];
	
	return cont;
}

ll _MergeSort(ll *A, ll *T, int In, int Fi){

	if(In >= Fi)
		return 0;

	int Med= (In+Fi)/2;

	return _MergeSort(A, T, In, Med) +
		   _MergeSort(A, T, Med+1, Fi) +
		   Merge(A, T, In, Med, Fi);

}

ll Mergesort(ll *A, int In, int Fi){
	return _MergeSort(A, T, In, Fi-1);
}

int main(){

	int t;

	while(scanf("%d", &t) != EOF){

		for (int i= 0; i<t; ++i)
			scanf("%lld", &A[i]);
		
		printf("Minimum exchange operations : %lld\n", Mergesort(A, 0, t));

	}

	return 0;
}