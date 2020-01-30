
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 11799 - Horror Dash                    *
*****************************************************************
*/

#include <cstdio>
#include <iostream>
using namespace std;

int main(){

	int n, e, v, aux=0;
	scanf("%d",&n);

	for(int i= 0; i<n; i++){

		scanf("%d",&e);
		for(int j= 0; j<e; j++){
			scanf("%d",&v);
			if(v>aux) aux= v;
		}
		printf("Case %d: %d\n",i+1,aux);
		aux= 0;
		
	}

	return 0;
}
