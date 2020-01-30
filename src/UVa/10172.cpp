
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*           UVa 10172 - The Lonesome Cargo Distributor          *
*****************************************************************
*/

#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

stack<int> P;
queue <int> C[105];

int S(int cant, int n, int s, int q){

	int cont= 0;

	for(int i= 0; cant>0; ++i){

		while(!P.empty() && C[i%n + 1].size() < q){
			
			if(P.top() != i%n+1)
				C[i%n + 1].push(P.top());	
			else
				--cant;

			++cont;
			P.pop();
			
		}

		while(!P.empty() && P.top() == i%n + 1){

			++cont;
			--cant;
			P.pop();

		}
		
		while(P.size() < s && !C[i%n + 1].empty()){

			P.push(C[i%n + 1].front());
			C[i%n + 1].pop();

			++cont;

		}

		if(cant>0)
			cont+= 2;

	}

	return cont;
}

int main(){

	int t, n, s, q, cant, aux, aux2;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		scanf("%d %d %d", &n, &s, &q);

		cant=  0;
		for(int j= 0; j<n; ++j){
			scanf("%d", &aux);

			cant+= aux;
			for(int k= 0; k<aux; ++k){
				scanf("%d", &aux2);

				C[j+1].push(aux2);
			}
		}

		printf("%d\n", S(cant, n, s, q));

	}

	return 0;
}