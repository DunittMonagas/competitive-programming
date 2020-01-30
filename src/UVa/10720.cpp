
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                UVa 10720 - Graph Construction                 *
*****************************************************************
*/

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

#define TAM 10010

typedef unsigned long long ll;

ll A[TAM];

int main(){

	int n;
	bool f;
	ll aux, aux2;

	while(scanf("%d", &n) != EOF && n != 0){

		aux= 0;
		for(int i= 1; i<=n; ++i){

			scanf("%lld", &A[i]);
			aux+= A[i];

		}

		if(aux%2 != 0){

			printf("Not possible\n");
			continue;

		}

		sort(A+1, A+n+1, greater<ll>());

		f= true;
		for(int k= 1; k<=n && f; ++k){

			aux2= 0;
			for(int i= 1; i<=k; ++i)
				aux2+= A[i];

			aux= 0;
			for(int j= k+1; j<=n; ++j)
				aux+= min(A[j], (ll)k);

			if(aux2 > k*(k-1) + aux)
				f= false;

		}

		(f ? printf("Possible\n"):printf("Not possible\n"));

	}

	return 0;
}