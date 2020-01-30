#include <stdlib.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
int main(){
	int c, nc;
	char cuenta[35], linea[35];
	map <string,int> mapa;
	map <string,int>::iterator it;
	scanf("%d", &c);
	for(int i=0; i<c; ++i){
		scanf("%d", &nc);
		cin.get();
		for(int j=0; j<nc; ++j){
			gets(cuenta);
			string str= cuenta;
			mapa[str]++;
		}
		gets(linea);
		for(it=mapa.begin(); it!=mapa.end(); ++it){
			cout << it->first;
			printf("%d\n", it->second);
		}
		printf("\n");
		mapa.clear();
	}
	return 0;
}
