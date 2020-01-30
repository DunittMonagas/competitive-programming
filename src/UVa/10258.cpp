
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*               UVa 10258 - Contest Scoreboard                  *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Equipo{

	bool S;
	int Eq;
	int Tp;
	int Cpr;
	int Pen[10];

};

Equipo E[110];
char str[100];

bool Cmp(const struct Equipo &A, const struct Equipo &B){

	if (A.Cpr != B.Cpr)
		return A.Cpr > B.Cpr;
	
	if(A.Tp != B.Tp)
		return A.Tp < B.Tp;

	return A.Eq < B.Eq;

}

int main(){

	char l;
	int t, e, p, tp;

	scanf("%d\n", &t);

	for (int i= 0; i<t; ++i){

		while(fgets(str, 100, stdin) && str[0] != '\n'){

			sscanf(str, "%d %d %d %c", &e, &p, &tp, &l);

			E[e].S= true;
			E[e].Eq= e;
			if(E[e].Pen[p] != -1){

				if(l == 'C'){

					E[e].Cpr++;
					E[e].Tp+= tp + E[e].Pen[p]*20;
					E[e].Pen[p]= -1;

				}else{

					if(l == 'I')
						E[e].Pen[p]++;
					
				}
			}

		}

		sort(E, E+105, Cmp);
		
		for (int j= 0; j<105; ++j)
			if(E[j].S)
				printf("%d %d %d\n", E[j].Eq, E[j].Cpr, E[j].Tp);	
		
		if(i+1 != t)
			printf("\n");

		memset(E, 0, sizeof(E));

	}
	

	return 0;
}