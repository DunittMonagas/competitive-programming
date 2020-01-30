#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	int c, a, m;
	bool t=false;
	string linea;
	scanf("%d", &c);
	map <string,int> mat;
	for(int f=1; f<=c; f++){
		scanf("%d %d",  &a, &m);
		cin.get();
		for(int i=0; i<m; i++){
			getline(cin, linea);
			if(!t){
				if(mat[linea]<1 ? mat[linea]++: t=true);
			}
		}
		if(t ? printf("Scenario #%d: impossible \n", f):printf("Scenario #%d: possible \n", f));
		mat.clear();
		t=false;
	}
	return 0;
}
