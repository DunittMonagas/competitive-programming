#include <iostream>
#include <string>
using namespace std;
int main(){
	int n, tam, in;
	string pal, inv;
	cin >> n;
	cin.get();
	for(int i=0; i<n; i++){
		getline (cin , pal);
		tam=pal.size();
		in=0;
		for(int j=0; j<tam; j++){
			if(pal[j]==' '){
				inv.insert(0, pal, in, j-in);
				inv.insert(0, " ");
				in=j+1;
			}
		}
		inv.insert(0, pal, in, tam-in);
		cout << inv << endl;
		inv.clear();
	}
	return 0;
}
