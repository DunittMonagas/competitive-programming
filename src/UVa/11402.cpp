
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                   UVa 11402 - Ahoy, Pirates!                  *
*****************************************************************
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


#define SO -1
#define BAR 0
#define BUC 1
#define INV 2
#define TAM 1030000

typedef vector<int> vi;

char A[TAM];

class SegmentTree{
	
	public:
		int n;
		vi T, Lz;

		int left(int x){
			return x << 1;
		}

		int right(int x){
			return (x << 1) + 1;
		}

		void build_st(const char *A, int p, int L, int R){

			if(L == R)
				T[p]= A[L];
			else{

				build_st(A, left(p), L, (L + R)/2);
				build_st(A, right(p), (L + R)/2 + 1, R);

				T[p]= T[left(p)] + T[right(p)];
			}

		}

		void Asignar(int ind, int valor){

			if(valor == INV){

				if(Lz[left(ind)] == BAR)
					Lz[left(ind)]= BUC;
				else
					if(Lz[left(ind)] == BUC)
						Lz[left(ind)]= BAR;
					else
						if(Lz[left(ind)] == SO)
							Lz[left(ind)]= INV;
						else
							Lz[left(ind)]= SO;

				if(Lz[right(ind)] == BAR)
					Lz[right(ind)]= BUC;
				else
					if(Lz[right(ind)] == BUC)
						Lz[right(ind)]= BAR;
					else
						if(Lz[right(ind)] == SO)
							Lz[right(ind)]= INV;
						else
							Lz[right(ind)]= SO;

			}else
				Lz[left(ind)]= Lz[right(ind)]= valor;

		}

		void Propagar(int p, int L, int R, int i, int j){

			if(Lz[p] != SO){

				if(Lz[p] == BAR)
					T[p]= BAR;
				else
					if(Lz[p] == BUC)
						T[p]= (R - L + 1);
					else
						T[p]= (T[p] ? (R - L + 1) - T[p] : (R - L + 1));

				if(L != R)
					Asignar(p, Lz[p]);

				Lz[p]= SO;
			}

		}

		void updateRange(int p, int L, int R, int i, int j, int valor){

			Propagar(p, L, R, i, j);

			if(R < i || L > j)
				return;

			if(L >= i && R <= j){

				if(valor == BAR)
					T[p]= BAR;
				else
					if(valor == BUC)
						T[p]= (R - L + 1);
					else
						T[p]= (T[p] ? (R - L + 1) - T[p] : (R - L + 1));

				if(L != R)
					Asignar(p, valor);

				return;

			}

			updateRange(left(p), L, (L + R)/2, i, j, valor);
			updateRange(right(p), (L + R)/2 + 1, R, i, j, valor);

			T[p]= T[left(p)] + T[right(p)];

		}

		int queryRange(int p, int L, int R, int i, int j){

			if(R < i || L > j)
				return 0;

			Propagar(p, L, R, i, j);
			
			if(L >= i && R <= j)
				return T[p];

			int p1= queryRange(left(p), L, (L + R)/2, i, j);
			int p2= queryRange(right(p), (L + R)/2 + 1, R, i, j);

			return p1 + p2;

		}

	public:

		SegmentTree(const char *str, int tam){

			n= tam;	
			T.assign(4*n, 0);
			Lz.assign(4*n, SO);
			build_st(str, 1, 0, n-1);

		}

		void Actualizar(int i, int j, int valor){
			updateRange(1, 0, n-1, i, j, valor);
		}

		int Consultar(int i, int j){
			return queryRange(1, 0, n-1, i, j);
		}
};

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char p;
	string str;
	int t, c, r, aux, aux2, q;

	cin >> t;
	for(int i= 0; i<t; ++i){
		
		aux2= q= 0;
		cin >> c;
		for(int j= 0; j<c; ++j){

			cin >> r >> str;

			for(int k= 0; k<r; ++k)
				for(int x= 0; x<str.size(); ++x)
					A[aux2++]= (int)(str[x] - '0');

		}

		SegmentTree S(A, aux2);

		cin >> c;

		cout << "Case " << i+1 << ":\n";
		for(int j= 0; j<c; ++j){

			cin >> p >> aux >> aux2;

			if(p == 'F')
				S.Actualizar(aux, aux2, BUC);
			else
				if(p == 'E')
					S.Actualizar(aux, aux2, BAR);
				else
					if(p == 'I')
						S.Actualizar(aux, aux2, INV);
					else{
						r= S.Consultar(aux, aux2);
						cout << "Q" << ++q << ": " << r << "\n";
					}

		}

		memset(A, 0, sizeof(A));

	}

	return 0;
}