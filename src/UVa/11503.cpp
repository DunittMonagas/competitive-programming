
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 11503 - Virtual Friends                  *
*****************************************************************
*/

#include <cstdio>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;

class Union{

	private:
		vi C, R, T;

	public:
		Union(int n){

			C.assign(n+1, 0);
			R.assign(n+1, 0);
			T.assign(n+1, 1);
			for(int i= 0; i<=n; ++i)
				C[i]= i;

		}

		int findSet(int i){
			return (C[i] == i ? i : C[i]= findSet(C[i]));
		}

		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}

		void unionSet(int i, int j){

			if(!isSameSet(i,j)){

				int x= findSet(i), y= findSet(j);

				if(R[x] > R[y]){
					C[y]= x;
					T[x]+= T[y];
				}else{

					C[x]= y;
					T[y]+= T[x];
					if(R[x] == R[y])
						++R[y];
				}
			}

		}

		int sizeOfSet(int i){
			return T[findSet(i)];
		}

};

int main(){

	int t, cont, x, y, n;
	char str[25], str2[25];

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		cont= 1;
		Union A(100000);
		map<string, int> D;
		map<string, int>:: iterator it;

		scanf("%d\n", &n);

		for(int j= 0; j<n; ++j){
			scanf("%s %s\n", str, str2);

			it= D.find(str);
			x= (it != D.end() ? it->second : D[str]= cont++);

			it= D.find(str2);
			y= (it != D.end() ? it->second : D[str2]= cont++);

			A.unionSet(x,y);
			printf("%d\n", A.sizeOfSet(x));

		}

	}

	return 0;
}