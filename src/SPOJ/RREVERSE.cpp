#include <iostream>
using namespace std;
int main(){
	int num, inv=0;
	while(cin >> num){
		while(num>0){
			inv=inv*10+(num%10);
			num/=10;
		}
		cout << inv << endl;
		inv=0;
	}
	return 0;
}
