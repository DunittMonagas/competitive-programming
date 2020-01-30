#include <iostream>
using namespace std;
int main(){
	int n, m, res=540, h, min;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> m;
		res+=m;
		h=res/60;
		min=res%60;	
		if(h>=24){
			h%=24;
		}
		cout << "Scenario #" << i+1 << ": ";
		cout << (h<10 ? "0" : "") << h << ":";
		cout << (min<10 ? "0" : "") << min << endl;
		res=540;
	}
	return 0;
}
