
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 10360 - Rat Attack                     *
*****************************************************************
*/

#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

#define VALIDO(f, c) (f >= 0 && f < 1025 && c >= 0 && c < 1025)

int C[1025][1025];
int m, rf, rc;

int main(){

	char aux[10];
	int c, d, n, x, y, r;

	scanf("%d", &c);

	for(int i= 0; i<c; ++i){

		scanf("%d", &d);

		scanf("%d", &n);

		m= rf= rc= 0;

		for(int j= 0; j<n; ++j){
		
			scanf("%d %d %d", &x, &y, &r);

			for(int f= x-d; abs(f-x)<= d; ++f){
				for(int c= y-d; abs(c-y)<= d; ++c){
					if(VALIDO(f, c)){
				
						C[f][c]+= r;
						
						if((m < C[f][c]) || 
						   (m == C[f][c]) && ((f < rf) or (f == rf && c < rc))){
						
							m= C[f][c];
							rf= f;
							rc= c;

						}

					}
				}
			}

		}

		printf("%d %d %d\n", rf, rc, m);

		memset(C, 0, 1050625*sizeof(int));

	}

	return 0;
}