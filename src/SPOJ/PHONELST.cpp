
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  SPOJ PHONELST - Phone List                   *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

#define MAXPAL 100

struct Nodo{

	bool P;
	Nodo *H[12];

	Nodo(){

		P= false;
		for (int i = 0; i<12; ++i)
			H[i]= NULL;

	}

};

Nodo *Raiz;

bool Agregar(const char *str){

	int n= strlen(str);
	Nodo *Actual= Raiz;

	for (int i = 0; i<n; ++i){

		if((i+1 == n && Actual->H[str[i]-'0'] != NULL) || (Actual->P))
			return false;

		if(Actual->H[str[i]-'0'] == NULL)
			Actual->H[str[i]-'0']= new Nodo();

		Actual= Actual->H[str[i]-'0'];

	}

	return Actual->P= true;

}

char str[MAXPAL];

int main(){

	bool f;
	int n, l;

	scanf("%d", &n);

	for(int i= 0; i<n; ++i){

		f= true;
		Raiz= new Nodo();

		scanf("%d", &l);
		for(int j= 0; j<l; ++j){

			scanf("%s", str);
			if(f)
				f= Agregar(str);

		}

		(f ? printf("YES\n") : printf("NO\n"));

	}

	return 0;
}