
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                     UVa 612 - DNA Sorting                     *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 110
#define MAXPAL 55

typedef struct A{
	int id;
	int inv;
	char str[MAXPAL];
}A;

A P[MAX];
char T[MAXPAL];

bool Comp(const A &x, const A &y){

	return ((x.inv != y.inv) ? x.inv < y.inv : x.id < y.id);

}

int Merge(char *L, char *Temp, int In, int Med, int Fi){

	int i= In, j= Med+1, t= In, cont= 0;

	while(i <= Med && j <= Fi)
		if(L[i] <= L[j])
			Temp[t++]= L[i++];
		else{
			Temp[t++]= L[j++];
			cont+= Med-i+1;
		}

	while(i <= Med)
		Temp[t++]= L[i++];

	while(j <= Fi)
		Temp[t++]= L[j++];

	for(int i= In; i<=Fi; ++i)
		L[i]= Temp[i];

	return cont;

}

int _MergeSort(char *L, char *Temp, int In, int Fi){

	if(In >= Fi)
		return 0;

	int Med= (In+Fi)/2;

	return _MergeSort(L, Temp, In, Med) +
		   _MergeSort(L, Temp, Med+1, Fi) +
		   Merge(L, Temp, In, Med, Fi);

}

int MergeSort(char *L, int In, int Fi){
	
	char Ln[MAXPAL];
	strncpy(Ln, L, Fi);
	Ln[Fi]= '\0';
	return _MergeSort(Ln, T, In, Fi-1);

}

int main(){

	int t, n, m;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		scanf("%d %d\n", &n, &m);

		for (int j= 0; j<m; ++j){
			
			P[j].id= j;
			scanf("%s", P[j].str);
			P[j].inv= MergeSort(P[j].str, 0, n);

		}

		sort(P, P+m, Comp);

		for (int j= 0; j<m; ++j)
			printf("%s\n", P[j].str);

		if(i+1 != t)
			printf("\n");

	}

	return 0;
}