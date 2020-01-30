
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*            Live Archive 6789 - Superstitious Socks            *
*****************************************************************
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<long long int, long long int> ll;

long long int M[100010];

class Comp{
	public:

		bool operator()(const ll &a, const ll &b) const{

			long long int da, db;
			da= abs(M[a.first] - M[a.second]);
			db= abs(M[b.first] - M[b.second]);

			return (da != db ? da > db : a.first > b.first);

		}
};

int main(){

	long long int n, k, a, b, cont;

	scanf("%lld %lld", &n, &k);

	while(n != 0 && k != 0){

		cont= 0;
		priority_queue<ll, vector<ll>, Comp> C;

		for(int i= 0; i<n; ++i)
			scanf("%lld", &(M[i]));
		
		sort(M, M+n);
		for(int i= 1; i<n; ++i)
			C.push(make_pair(i-1, i));

		while(!C.empty()){

			++cont;
			ll aux= C.top();
			C.pop();

			if(cont == k){
				printf("%lld %lld\n", M[aux.first], M[aux.second]);
				break;
			}
			
			if(aux.second+1 < n){
				++aux.second;
				C.push(aux);
			}

		}

		scanf("%lld %lld", &n, &k);
	}

	return 0;
}