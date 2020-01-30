
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                SPOJ MATSUM - Matrix Summation                 *
*****************************************************************
*/

#include <cstdio>
#include <vector>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

class Fenwick{
	private:
		ll n;
		vvll T;

		void Incrementar(ll x, ll y, ll valor){

			for(; x <= n; x+= (x & -x))
				for(ll y1= y; y1 <= n; y1+= (y1 & -y1))
					T[x][y1]+= valor;

		}

	public:

		Fenwick(ll tam){
			n= tam;
			T.assign(n+1, vll(n+1, 0));
		}

		ll Consulta(ll x, ll y){

			ll res= 0;
			for(; x; x-= (x & -x))
				for(ll y1= y; y1; y1-= (y1 & -y1))
					res+= T[x][y1];
			return res;

		}

		void Asignar(ll x, ll y, ll valor){
			valor-= (Consulta(x, y) - Consulta(x-1, y)
					- Consulta(x, y-1) + Consulta(x-1, y-1));
			this->Incrementar(x, y, valor);
		}

		ll Consulta(ll x1, ll y1, ll x2, ll y2){
			return Consulta(x2, y2) -  Consulta(x1-1, y2)
				   - Consulta(x2, y1-1) + Consulta(x1-1, y1-1);
		}

};

int main(){

	char str[5];
	ll t, n, x1, y1, x2, y2, aux;

	scanf("%lld", &t);

	for(ll i= 0; i<t; ++i){

		scanf("%lld\n", &n);

		Fenwick F(n);

		while(scanf("%s", str) != EOF && str[0] != 'E'){

			if(str[1] == 'E'){
				scanf("%lld %lld %lld\n", &x1, &y1, &aux);
				F.Asignar(x1+1, y1+1, aux);
			}else{
				scanf("%lld %lld %lld %lld\n", &x1, &y1, &x2, &y2);
				aux= F.Consulta(x1+1, y1+1, x2+1, y2+1);
				printf("%lld\n", aux);
			}

		}

		printf("\n");

	}

	return 0;
}