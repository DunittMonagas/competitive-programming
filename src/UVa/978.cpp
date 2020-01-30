
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*  	                UVa 978 - Lemmings Battle!                  *
*****************************************************************
*/

#include <cstdio>
#include <set>

using namespace std;

int A[100000];

bool fncomp(int a, int b){
	return a > b;
}

int main(){

	int t, bt, gr, bl, ar;
	multiset<int>::iterator it;
	bool(*fn_pt)(int, int)= fncomp;
	multiset<int, bool(*)(int, int) > B(fn_pt), G(fn_pt);

	scanf("%d", &t);

	while(t--){

		scanf("%d %d %d", &bt, &gr, &bl);

		for(int i= 0; i<gr; ++i){
			scanf("%d", &ar);
			G.insert(ar);
		}

		for(int i= 0; i<bl; ++i){
			scanf("%d", &ar);
			B.insert(ar);
		}

		while(G.size() && B.size()){

			for(ar= 0; ar<bt; ++ar){

				if(!G.size() || !B.size())
					break;

				gr= *(G.begin());
				G.erase(G.begin());

				bl= *(B.begin());
				B.erase(B.begin());

				A[ar]= gr - bl;

			}

			for(int i= 0; i<ar; ++i)
				if(A[i] < 0)
					B.insert(-A[i]);
				else if(A[i] > 0)
					G.insert(A[i]);
				
		}


		if(!G.size() && !B.size())
			printf("green and blue died\n");
		else if(!B.size()){

			printf("green wins\n");
			for(it= G.begin(); it != G.end(); ++it)
				printf("%d\n", *it);

		}else{

			printf("blue wins\n");
			for(it= B.begin(); it != B.end(); ++it)
				printf("%d\n", *it);

		}

		if(t != 0) printf("\n");

		G.clear();
		B.clear();

	}

	return 0;
}