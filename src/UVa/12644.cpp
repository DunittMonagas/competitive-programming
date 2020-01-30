
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 12644 - Vocabulary                     *
*****************************************************************
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define LIBRE 0
#define ABC 256
#define MAX 1010
#define INF (1 << 30)

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;

vs P;
vi MA, D;
vii M, G;

void PCM(int l){

	int n= P[l].size();

	for(int i= 0; i<n; ++i)
		++M[l][P[l][i]];

}


void PCG(int v, int c){

	bool b;

	for(int i= 1; i<=v; ++i)
		for(int j= v+1; j<=v+c; ++j){

			b= true;

			if(P[i].size() < P[j].size())
				continue;

			for(int k= 0; k<P[j].size() && b; ++k)
				if(M[i][P[j][k]] < M[j][P[j][k]])
					b= false;
				
			if(b)
				G[i].push_back(j);
			
		}

}

bool BFS(int n){

	queue<int> C;
	D[LIBRE]= INF;
	int act, v, nv;

	for(int i= 1; i<=n; ++i)
		if(MA[i] == LIBRE){
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
				if(D[MA[v]] == INF){
					D[MA[v]]= D[act] + 1;
					C.push(MA[v]);
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
			if(D[MA[v]] == D[act] + 1 && DFS(MA[v])){
				MA[act]= v;
				MA[v]= act;
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
			if(MA[i] == LIBRE && DFS(i))
				++rest;
	
	return rest;

}

int main(){

	int c, v;
	string str;

	while(cin >> v >> c){

		D.assign(v + c + 1, 0);
		P.assign(v + c + 1, "");
		MA.assign(v + c + 1 , 0);
		G.assign(v + c + 1, vi());
		M.assign(v + c + 1, vi(ABC, 0));

		for(int i= 1; i<=v + c; ++i){

			cin >> P[i];
			PCM(i);

		}

		PCG(v, c);
		cout << MCBM(v) << endl;

	}

	return 0;
}