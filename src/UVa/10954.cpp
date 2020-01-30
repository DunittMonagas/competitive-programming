
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                     UVa 10954 - Add All                       *
*****************************************************************
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main(){

	ll a, b, r;
	int n, aux;

	scanf("%d", &n);

	while(n != 0){

		priority_queue<ll, vector<ll>, greater<ll> > C;

		for(int i= 0; i<n; ++i){

			scanf("%d", &aux);
			C.push(aux);

		}

		r= 0;
		while(C.size() > 1){

			a= C.top();
			C.pop();

			b= C.top();
			C.pop();

			r+= a+b;
			C.push(a+b);
			
		}

		printf("%lld\n", r);
		scanf("%d", &n);

	}

	return 0;
}