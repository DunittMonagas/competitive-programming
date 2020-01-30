
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*               Codeforce 546B - Soldier and Badges             *
*****************************************************************
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int A[3010];

int main(){

	int n, cont= 0;

	scanf("%d", &n);

	for(int i= 0; i<n; ++i)
		scanf("%d", &A[i]);

	sort(A, A+n);

	for(int i= 0; i<n-1; ++i)
		while(A[i] >= A[i+1]){
			++A[i+1];
			++cont;
		}

	printf("%d\n", cont);

	return 0;
}
