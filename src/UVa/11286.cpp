
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                   UVa 11286 - Conformity                      *
*****************************************************************
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int n, mx, cont, aux;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while(n != 0){

		mx= -1;
		cont= 0;
		map<vector<int>, int> C;
		map<vector<int>, int>::iterator it;

		for(int i= 0; i<n; ++i){

			vector<int> cl;

			for(int k= 0; k<5; ++k){

				cin >> aux;
				cl.push_back(aux);

			}
			
			sort(cl.begin(), cl.end());

			mx= max(mx, ++C[cl]);
			
		}

		for(it= C.begin(); it!=C.end(); ++it)
			if(it->second == mx)
				cont+= mx;

		cout << cont << "\n";

		cin >> n;

	}

	return 0;
}
