#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(){
	int t, pal, in, tam;
	string str, inv;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &pal);
		cin.get();
		getline(cin, str);
		tam= str.size();
		in= str.find_first_not_of("# ");
		pal= in;
		if(in!=-1){
			for(int j=in; j<tam; j++){
				if(str[j]==' '){
					inv.insert(0, str, in, j-in);
					inv.insert(0, " ");
					in=j+1;
				}
			}
			inv.insert(0, str, in, tam-in);
			inv+=" ";
			inv.append(str, 0, pal-1);
			cout << inv << endl;
			inv.clear();
		}else{
			cout << str << endl;
		}
	}
	return 0;
}
