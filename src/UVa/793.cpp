
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 793 - Network Connections                *
*****************************************************************
*/

#include <cstdio>
#include <vector>

using namespace std;

#define TAM 1000000

char str[20];
int C[TAM], R[TAM], T[TAM];


void initSet(int n){

	for(int i= 0; i<=n; ++i){
		R[i]= 0;
		T[i]= 1;
		C[i]= i;
	}

}

int findSet(int i){
	return (C[i] == i ? i : C[i]= findSet(C[i]));
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j){
	if(!isSameSet(i, j)){

		int x= findSet(i), y= findSet(j);

		if(R[x] > R[y]){
			C[y]= x;
			T[x]= +T[y];

		}else{
			C[x]= y;
			T[y]+= T[x];
			if(R[x] == R[y])
				++R[y];
		}
	}
}


int main(){

	char l;
	int t, n, a, b, cn, nc;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		scanf("%d\n", &n);

		cn= nc= 0;
		initSet(n);
		while(fgets(str, 20, stdin) && str[0] != '\n'){

			sscanf(str, "%c %d %d\n", &l, &a, &b);

			if(l == 'c')
				unionSet(a, b);
			else
				(isSameSet(a, b) ? ++cn : ++nc);

		}

		printf("%d,%d\n", cn, nc);

		if(i+1 != t)
			printf("\n");

	}

	return 0;
}