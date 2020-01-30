
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                        UVa 11849 - CD                         *
*****************************************************************
*/

#include <cstdio>
#include <map>

using namespace std;

int main(){

	int n, m, aux, cont;

	scanf("%d %d", &n, &m);

	while(n != 0 || m != 0){

		cont= 0;
		map<int, int> CD;
		map<int, int>::iterator it;

		for(int i= 0; i<n+m; ++i){

			scanf("%d", &aux);

			it= CD.find(aux);

			if(it == CD.end())
				CD.insert(pair<int,int>(aux, 1));
			else
				++cont;

		}

		printf("%d\n", cont);
		scanf("%d %d", &n, &m);
		
	}

	return 0;
}