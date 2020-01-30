
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 Codeforce 52C - Circular RMQ                  *
*****************************************************************
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#ifdef _WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define TAM 200010
#define INF 1000000000000

typedef long long int ll;
typedef vector<ll> vll;

ll A[TAM];

class SegmentTree{

	private:
		int n;
		vll T, Lz;

		int left(int x){
			return x << 1;
		}

		int right(int x){
			return ((x << 1) | 1);
		}

		void build_st(const ll *A, int p, int L, int R){

			if(L == R)
				T[p]= A[L];
			else{
				build_st(A, left(p), L, (L+R)/2);
				build_st(A, right(p), (L+R)/2+1, R);

				T[p]= min(T[left(p)], T[right(p)]);
			}
			
		}

		void Propagar(int p, int L, int R){

			if(Lz[p]){
				T[p]+= Lz[p];

				if(L != R){
					Lz[left(p)]+= Lz[p];
					Lz[right(p)]+= Lz[p];
				}

				Lz[p]= 0;
			}

		}

		void updateRange(int p, int L, int R, int i, int j, ll valor){

			Propagar(p, L, R);

			if(R < i || L > j)
				return;

			if(L >= i && R <= j){

				T[p]+= valor;

				if(L != R){
					Lz[left(p)]+= valor;
					Lz[right(p)]+= valor;
				}

				return;
			}

			updateRange(left(p), L, (L+R)/2, i, j, valor);
			updateRange(right(p), (L+R)/2+1, R, i, j, valor);

			T[p]= min(T[left(p)], T[right(p)]);

		}

		ll rmq(int p, int L, int R, int i, int j){

			if(R < i || L > j)
				return INF;

			Propagar(p, L, R);

			if(L >= i && R <= j)
				return T[p];
			
			ll p1= rmq(left(p), L, (L+R)/2, i, j);
			ll p2= rmq(right(p), (L+R)/2+1, R, i, j);
			
			return min(p1, p2);

		}

	public:

		SegmentTree(const ll *A, int t){

			n= t;
			T.assign(4*n, INF);
			Lz.assign(4*n, 0);
			build_st(A, 1, 0, n-1);

		}

		void Actualizar(int i, int j, int valor){
			updateRange(1, 0, n-1, i, j, valor);
		}

		ll Consultar(int i, int j){
			return rmq(1, 0, n-1, i, j);
		}

};

int main(){

	ll r;
	char *p, str[30];
	int n, m, cont, vl[5];

	scanf("%d", &n);

	for(int i= 0; i<n; ++i)
		scanf(LLD, &A[i]);

	SegmentTree S(A, n);

	scanf("%d\n", &m);
	for(int i= 0; i<m; ++i){

		fgets(str, 30, stdin);

		cont= 0;
		p= strtok(str, " ");
		while(p != NULL){
			vl[cont++]= atoi(p);
			p= strtok(NULL, " ");
		}

		if(cont == 2){
			r= (vl[0] > vl[1] ? (min(S.Consultar(vl[0], n-1), S.Consultar(0, vl[1]))): 
				S.Consultar(vl[0], vl[1]));
			printf(LLD, r);
			printf("\n");
		}else
			if(vl[0] > vl[1]){
				S.Actualizar(vl[0], n-1, vl[2]);
				S.Actualizar(0, vl[1], vl[2]);
			}else
				S.Actualizar(vl[0], vl[1], vl[2]);
		
	}
	
	return  0;
}