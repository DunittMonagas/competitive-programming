
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 10812 - Beat the Spread!                 *
*****************************************************************
*/

#include <cstdio>
#include <cmath>
using namespace std;

int main(){

	long long int n, s ,d;
	long long int x, y;

	scanf("%lld", &n);

	for(long long int i= 0; i<n; i++){

		scanf("%lld %lld", &s, &d);

		y = (s - d) / 2;
		x = s - y;

		if( x >= 0 && y >= 0 && (x + y == s) && (abs(x - y) == d))
			printf("%lld %lld\n", x, y);
		else
			printf("impossible\n");
			
	}

}