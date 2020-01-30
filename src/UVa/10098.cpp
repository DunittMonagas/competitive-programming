
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 10098 - Generating Fast                  *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[10];

int main(){

	int n, tam;

	scanf("%d\n", &n);

	for(int i= 0; i<n; i++){

		scanf("%s\n", str);

		tam= strlen(str);
		sort(str, str + tam);

		do{
			printf("%s\n", str);
		}while(next_permutation(str, str + tam));

		printf("\n");

	}

	return 0;
}