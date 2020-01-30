
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*           UVa 11221 - Magic square palindromes.               *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <cmath>

char str[15000];

int main(){

	bool pal;
	int n, i, j, cont;

	scanf("%d\n", &n);

	for(int t= 0; t<n; t++){

		fgets(str, 15000, stdin);

		pal= true;
		cont= i= 0;
		j= strlen(str) - 2;

		while(i <= j){

			if(str[i] == ' ' || str[i] == ',' || str[i] == ';' || str[i] == '?' || str[i] == '!' || str[i] == '(' || str[i] == ')' || str[i] == '.'){

				++i;
				continue;

			}

			if(str[j] == ' ' || str[j] == ',' || str[j] == ';' || str[j] == '?' || str[j] == '!' || str[j] == '(' || str[j] == ')' || str[j] == '.'){

				--j;
				continue;

			}

			if(str[i] == str[j]){

				if(i == j)
					++cont;
				else
					cont+= 2;

				++i;
				--j;

				continue;

			}else{

				pal= false;
				break;

			}

		}

		double aux;
		double r= sqrt(cont);

		if(pal && modf(r, &aux) == 0){		

			printf("Case #%d:\n%d\n", t+1, (int) r);

		}else
			printf("Case #%d:\nNo magic :(\n", t+1);

	}

	return 0;
}