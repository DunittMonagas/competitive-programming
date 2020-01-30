
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                     TJU 4116 - GCD's magic                    *
*****************************************************************
*/

#include <cstdio>

long long int MCD(long long int a, long long int b){
	
	while(b > 0){
		a %= b;
		a^= b;
		b^= a;
		a^= b;
	}

	return a;
}

int main(){

	bool f;
	long long int t, n, r, aux[2];

	scanf("%lld", &t);

	for(long long int i= 0; i<t; ++i){

		f= false;
		scanf("%lld", &n);

		for(long long int j= 0; j<n; ++j){
			scanf("%lld", &aux[j%2]);
			
			if(f)
				continue;

			if(aux[j%2] == 1)
				f= true;

			if(j == 0)
				r= aux[j%2];
			else{
				r= MCD(r, aux[j%2]);
				if(r == 1)
					f= true;
			}
			
		}

		f ? printf("1\n") : printf("%lld\n", r);

	}



	return 0;
}