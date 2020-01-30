
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 11742 - Social Constraints                *
*****************************************************************
*/

#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define a first.first
#define b first.second
#define c second

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int n;
int A[]= {0, 1, 2, 3, 4, 5, 6, 7};

inline void F(int x, int y, int *i, int *j){
	for(int k= 0; k<n; ++k){
		if(A[k] == x)
			*i= k;

		if(A[k] == y)
			*j= k;
	}
}

int main(){

	bool sol;
	iii cond[21];
	int m, cont, d1, d2;

	scanf("%d %d", &n, &m);
	
	while(n != 0 || m != 0){

		for(int i= 0; i<m; ++i)
			scanf("%d %d %d", &cond[i].a, &cond[i].b, &cond[i].c);

		cont= 0;
		do{

			sol= true;
			for(int i= 0; i<m && sol; ++i){
				F(cond[i].a, cond[i].b, &d1, &d2);
				
				if(cond[i].c > 0){
					if(abs(d1 - d2) > cond[i].c)
						sol= false;
				}else{
					if(abs(d1 - d2) < -cond[i].c)		
						sol= false;
				}
				
			}

			if(sol)
				++cont;

		}while(next_permutation(A, A+n));

		printf("%d\n", cont);
		scanf("%d %d", &n, &m);
		
	}

	return 0;
}