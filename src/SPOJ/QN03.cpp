#include <iostream>
#include <string>
using namespace std;
int main(){
	int n, m, cont;
	string bin;
	cin >> n;
	for(int i=0; i<n; i++){
		cont=0;
		cin >> bin;
		m=bin.find("1");
		while(m!=-1){
			for(unsigned int j=m; j<bin.length(); j++){
				if(bin[j]=='1'){
					bin[j]='0';
				}else{
					bin[j]='1';
				}
			}
			m=bin.find('1');
			cont++;
		}
		cout << cont << endl;
	}
	return 0;
}
