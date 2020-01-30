
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*  	              UVa 11572 - Unique Snowflakes                 *
*****************************************************************
*/

#include <map>
#include <cstdio>

using namespace std;

typedef pair<int,int> ii;


int main(){

	map<int, int> A;
	int first, last;
	int t, n, id, reslt;
	map<int, int>::iterator it;

	scanf("%d", &t);

	while(t--){

		reslt= 0;
		first= last= 0;

		scanf("%d", &n);
		for(int i= 0; i<n; ++i){

			scanf("%d", &id);

			it= A.find(id);
			if(it != A.end()){

				if(it->second >= first)
					first= it->second + 1;
				
				it->second= i;

			}else
				A.insert(it, ii(id, i));

			last= i;
			reslt= max(reslt, last - first + 1);
			
		}

		printf("%d\n", reslt);
		A.clear();

	}

	return 0;
}
