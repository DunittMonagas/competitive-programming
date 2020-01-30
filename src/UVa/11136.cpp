
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*   	           UVa 11136 - Hoax or what                     *
*****************************************************************
*/

#include <cstdio>
#include <set>

using namespace std;

int main(){

	int t, k, b;
	long long reslt;

	multiset<int> P;
	multiset<int>::iterator it, rit;

	while(scanf("%d", &t), t){

		reslt= 0;
		for(int i= 0; i<t; ++i){

			scanf("%d", &k);
			for(int j= 0; j<k; ++j){

				scanf("%d", &b);
				P.insert(b);

			}
			
			it= P.begin();
			rit= P.end();

			reslt+= *(--rit) - *it;

			P.erase(it);
			P.erase(rit);

		}

		printf("%lld\n", reslt);
		P.clear();

	}

	return 0;
}
