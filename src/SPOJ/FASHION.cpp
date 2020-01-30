
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  SPOJ FASHION - Fashion Shows                 *
*****************************************************************
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int H[1010], M[1010];

int main(){

	int t, n;
	long long int r;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		r= 0;
		scanf("%d", &n);
		for (int j= 0; j<n; ++j)
			scanf("%d", &H[j]);

		for (int j= 0; j<n; ++j)
			scanf("%d", &M[j]);

		sort(H, H+n);
		sort(M, M+n);

		for(int j= 0; j<n; ++j)
			r+= H[j]*M[j];

		printf("%lld\n", r);

	}

	return 0;
}