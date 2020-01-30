
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 SPOJ NKMOBILE - IOI01 Mobiles                 *
*****************************************************************
*/

#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Fenwick{
	private:
		int n;
		vvi T;

	public:

		Fenwick(int tam){
			n= tam;
			T.assign(n+1, vi(n+1, 0));
		}

		int Consulta(int x, int y){

			int res= 0;
			for(; x; x-= (x & -x))
				for(int y1= y; y1; y1-= (y1 & -y1))
					res+= T[x][y1];
			return res;

		}

		void Incrementar(int x, int y, int valor){

			for(; x <= n; x+= (x & -x))
				for(int y1= y; y1 <= n; y1+= (y1 & -y1))
					T[x][y1]+= valor;

		}

		int Consulta(int x1, int y1, int x2, int y2){
			return Consulta(x2, y2) -  Consulta(x1-1, y2)
				   - Consulta(x2, y1-1) + Consulta(x1-1, y1-1);
		}

};

int main(){

	Fenwick F(0);
	int op, n, x1, y1, x2, y2, aux;

	while(scanf("%d", &op) != EOF && op != 3){

		if(op == 0){
			scanf("%d", &n);
			F= Fenwick(n);
		}else{
			if(op == 1){
				scanf("%d %d %d\n", &x1, &y1, &aux);
				F.Incrementar(x1+1, y1+1, aux);
			}else{
				scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
				aux= F.Consulta(x1+1, y1+1, x2+1, y2+1);
				printf("%d\n", aux);
			}
		}

	}
	
	return 0;
}