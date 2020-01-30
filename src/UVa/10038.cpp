
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*  	                UVa 10038 - Jolly Jumpers                   *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[3005];
bool B[3005];

int main(){

	int n;
	bool b;
	while(scanf("%d", &n) != EOF){

		for(int i= 0; i<n; ++i){
			scanf("%d", &A[i]);
			if(i > 0) B[abs(A[i-1] - A[i])]= true;
		}

		b= true;
		for(int i= 1; b && i<n; ++i)
			b= B[i];
		
		printf("%s\n", (b ? "Jolly" : "Not jolly"));

		memset(B, 0, n);

	}

	return 0;
}