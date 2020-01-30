
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                     UVa 11340 - Newspaper                     *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

double P[260];
unsigned char str[100010];

int main(){

	int n, k;
	double pre;
	unsigned char c;
	unsigned int tam;

	scanf("%d", &n);

	for(int i= 0; i<n; ++i){

		pre= 0.0;
		scanf("%d\n", &k);

		for (int j = 0; j<k; ++j){
			
			scanf("%c %lf\n", &c, &pre);
			P[c]= pre;

		}

		scanf("%d\n", &k);

		pre= 0.0;
		for (int j = 0; j<k; ++j){

			fgets((char*)str, sizeof(str), stdin);
			tam= (unsigned) strlen((char*)str)-1;

			for (int l = 0; l<tam; ++l)
				pre+= P[str[l]];

		}
		
		printf("%.2f$\n", pre/100.0);
		memset(P, 0.0, sizeof(P));

	}

	return 0;
}