
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*  	              UVa 10107 - What is the Median?               *
*****************************************************************
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int A[10005];
	
int main(){

	int a, n= 0;

	while(scanf("%d", &a) != EOF){

		A[n++]= a;
		nth_element(A, A + n/2, A+n);

		if(!(n%2))
			nth_element(A, A + n/2 - 1, A+n);

		printf("%d\n", (n%2 ? A[n/2]:(A[n/2] + A[n/2 - 1])/2));

	}

	return 0;

}