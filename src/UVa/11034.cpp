
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 11034 - Ferry Loading IV                 *
*****************************************************************
*/

#include <cstdio>
#include <queue>

using namespace std;

#define IZQ 0
#define DER 1
#define INF 100000000

int main(){

	bool f;
	int c, m, r;
	char str[10];
	float l, cont, aux;
	queue<float> L[2];
	
	scanf("%d", &c);

	for(int i= 0; i<c; ++i){

		scanf("%f %d", &l, &m);

		for(int j= 0; j<m; ++j){

			scanf("%f %s", &aux, str);
			(str[0] == 'r' ? L[DER].push(aux/100.0) : L[IZQ].push(aux/100.0));

		}

		r= 0;
		f= IZQ;
		while(!L[IZQ].empty() || !L[DER].empty()){

			cont= 0.0;
			while(!L[f].empty() && L[f].front() + cont <= l){

				cont+= L[f].front();
				L[f].pop();

			}

			++r;
			f= !f;

		}

		printf("%d\n", r);

	}

	return 0;
}