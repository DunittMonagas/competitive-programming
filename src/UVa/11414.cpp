
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                       UVa 11414 - Dream                       *
*****************************************************************
*/

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

#define TAM 1010

typedef unsigned long long ll;

ll A[TAM];

int main(){

	bool f;
	int t, n;
	ll aux, aux2;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){
		scanf("%d", &n);

		aux= 0;
		for(int j= 1; j<=n; ++j){
			scanf("%lld", &A[j]);

			aux+= A[j];
		}
		

		if(aux%2 != 0){
			printf("No\n");
			continue;
		}

		sort(A+1, A+n+1, greater<ll>());

		f= true;
		for(int k= 1; k<=n && f; ++k){

			aux= 0;
			for(int j= 1; j<=k; ++j)
				aux+= A[j];

			aux2= 0;
			for(int j= k+1; j<=n; ++j)
				aux2+= min(A[j], (ll)k);

			if(aux > k*(k-1) + aux2)
				f= false;

		}

		(f ? printf("Yes\n"):printf("No\n"));

	}

	return 0;
}