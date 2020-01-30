
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              Codeforce 525B - Pasha and String                *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[200500];
long long int R[100500];

int main(){

	int n, p;
	long long int aux;

	scanf("%s", str);
	scanf("%d", &n);

	for(int i= 0; i<n; ++i){

		scanf("%d ", &p);
		++R[p];

	}

	aux= 0;
	for(int i= 1; i<=strlen(str)/2; ++i){

		aux+= R[i];
		if(aux%2 != 0)
			swap(str[(i-1)], str[(strlen(str) - i)]);

	}
	
	printf("%s\n", str);


	return 0;
}