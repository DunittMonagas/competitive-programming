
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 10507 - Waking up brain                  *
*****************************************************************
*/

#include <cstdio>
#include <vector>
#include <bitset>

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
			if(!isSameSet(i, j)){
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

};

int main(){

	bool f;
	char str[5];
	int n, m, cont, temp;
	
	while(scanf("%d", &n) != EOF){

		vi T;
		bitset<26> Z;
		vector<Union> A(26, Union(26));

		scanf("%d\n", &m);

		scanf("%s\n", str);
		for(int i= 0; i<3; ++i)
			Z[str[i] - 'A']= true;

		for(int i= 0; i<m; ++i){
			scanf("%s\n", str);
			A[str[0]-'A'].unionSet(str[0]-'A', str[1]-'A');
			A[str[1]-'A'].unionSet(str[1]-'A', str[0]-'A');
		}

		cont= 0;
		f= true;
		while(Z.count() < n && f){
			
			f= false;
			for(int i= 0; i<Z.size(); ++i){

				temp= 0;
				if(!Z[i]){

					for(int j= 0; j<Z.size() && temp<3; ++j)
						if(Z[j] && A[i].isSameSet(i, j))
							++temp;
				
					if(temp == 3){
						T.push_back(i);
						
						if(!f)
							f= true;
					}

				}

			}

			for(int i= 0; i<T.size(); ++i)
				Z[T[i]]= true;
			T.clear();

			++cont;

		}

		(f ? printf("WAKE UP IN, %d, YEARS\n", cont) : printf("THIS BRAIN NEVER WAKES UP\n"));


	}

	return 0;
}