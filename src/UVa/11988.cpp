
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*         UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)       *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

char str[100010];

int main(){

	int tam;
	while(scanf("%s", str) != -1){

		list<char> L;
		list<char>::iterator it= L.begin();

		tam= strlen(str);
		for(int i= 0; i<tam; ++i)
			switch(str[i]){
				case '[':
					it= L.begin();
					break;
				case ']':
					it= L.end();
					break;
				default:
					L.insert(it, str[i]);
					break;
			};

		for(it= L.begin(); it!=L.end(); ++it)
			printf("%c", *it);
		printf("\n");


	}

	return 0;
}