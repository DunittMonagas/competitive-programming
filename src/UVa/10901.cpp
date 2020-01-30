
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 10901 - Ferry Loading III                 *
*****************************************************************
*/

#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

#define IZQ 0
#define DER 1
#define INF 1000000000
#define min(a, b) (a < b ? a : b);
#define max(a, b) (a > b ? a : b);


typedef long long int ll;
typedef pair<int,ll> ii;

ll A[10010];
queue<ii> L[2];

int main(){

	bool f;
	ll tp, aux;
	char str[10];
	int c, n, t, m, cont;

	scanf("%d", &c);

	for(int i= 0; i<c; ++i){

		scanf("%d %d %d", &n, &t, &m);

		for(int j= 0; j<m; ++j){

			scanf("%lld %s", &aux, str);
			(str[0] == 'r' ? L[DER].push(ii(j,aux)) : L[IZQ].push(ii(j,aux)));

		}


		tp= 0;
		f= IZQ;
		while(!L[IZQ].empty() || !L[DER].empty()){

			aux= INF;
			if(!L[IZQ].empty())
				aux= L[IZQ].front().second;			
			
			if(!L[DER].empty())
				aux= min(aux, L[DER].front().second);
			

			tp= max(tp, aux);

			cont= 0;
			while(!L[f].empty() && cont < n && L[f].front().second <= tp){

				++cont;
				A[L[f].front().first]= tp + t;
				L[f].pop();

			}

			tp+= t;
			f= !f;

		}

		for(int j= 0; j<m; ++j){

			printf("%lld\n", A[j]);
			A[j]= 0;

		}

		if(i+1 != c)
			printf("\n");

	}

	return 0;
}