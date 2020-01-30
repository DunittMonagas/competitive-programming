
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  Codeforce 349A - Cinema Line                 *
*****************************************************************
*/

#include <cstdio>

int main(){

	int n, aux;
	bool p= true;
	long long int V= 0;
	long long int C= 0;
	long long int Ci= 0;

	scanf("%d", &n);

	for(int i= 0; i<n && p; ++i){

		scanf("%d ", &aux);

		switch(aux){

			case 25:

				++V;
				break;

			case 50:

				++C;
				if(V - 1 >= 0)
					--V;
				else
					p= false;
			break;

			case 100:

				++Ci;
				if(C > 0 && V > 0){
					--C;
					--V;
				}else
					if(V > 2)
						V-= 3;
					else
						p= false;

				break;

		}

	}

	p ? printf("YES\n") : printf("NO\n");

	return 0;
	
}