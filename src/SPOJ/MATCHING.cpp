
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              SPOJ MATCHING - Fast Maximum Matching            *
*****************************************************************
*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define LIBRE 0
#define MAX 100010
#define INF (1 << 30)

typedef vector<int> vi;

vi G[MAX];
int M[MAX], D[MAX];

bool BFS(int n){

	queue<int> C;
	D[LIBRE]= INF;
	int act, v, nv;

	for(int i= 1; i<=n; ++i)
		if(M[i] == LIBRE){
			D[i]= 0;
			C.push(i);
		}else
			D[i]= INF;

	while(!C.empty()){

		act= C.front();
		C.pop();

		if(act != LIBRE){

			nv= G[act].size();
			for(int i= 0; i<nv; ++i){

				v= G[act][i];
				if(D[M[v]] == INF){
					D[M[v]]= D[act] + 1;
					C.push(M[v]);
				}

			}

		}

	}

	return (D[LIBRE] != INF);
}

int DFS(int act){

	int v, nv;

	if(act != LIBRE){

		nv= G[act].size();
		for(int i= 0; i<nv; ++i){

			v= G[act][i];
			if(D[M[v]] == D[act] + 1 && DFS(M[v])){
				M[act]= v;
				M[v]= act;
				return true;
			}

		}

		D[act]= INF;
		return false;

	}

	return true;

}

int MCBM(int n){

	int rest= 0;

	while(BFS(n))
		for(int i= 1; i<=n; ++i)
			if(M[i] == LIBRE && DFS(i))
				++rest;
	
	return rest;

}

int main(){

	int n, m, p, a, b;

	scanf("%d %d %d", &n, &m, &p);

	for(int i= 0; i<p; ++i){

		scanf("%d %d", &a, &b);
		G[a].push_back(n+b);

	}

	n= MCBM(n);
	printf("%d\n", n);

	return 0;
}