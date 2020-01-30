
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 11588 - Image Coding                   *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[30];

int main(){

	char l;
	int t, x, y, n, m, mx, res;

	scanf("%d", &t);

	for(int c= 0; c<t; ++c){

		mx= -1;
		res= 0;
		scanf("%d %d %d %d\n", &x, &y, &m, &n);

		for(int i= 0; i<x; ++i){
			for(int j= 0; j<y; ++j){
				scanf("%c", &l);
				A[l-'A']++;
				mx= max(mx, A[l-'A']);
			}
			getchar();
		}


		for(int i= 0; i<30; ++i)
			res+= (A[i] == mx ? A[i]*m : A[i]*n);
				
		printf("Case %d: %d\n", c+1, res);

		memset(A, 0, sizeof(A));

	}

	return 0;
}