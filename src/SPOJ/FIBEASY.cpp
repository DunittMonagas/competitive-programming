#include <iostream>
using namespace std;
void Fibo(int num){
	int n1=1, n2=1, aux=0;
	if(num<3){
		cout << (num==1 ? "1" : "1 1");
	}else{
		cout << "1 1";
		for(int j=0; j<num-2; j++){
			aux=n2;
			n2+=n1;
			n1=aux;
			cout << " " << n2;
		}
	}
}
int main(){
	int n, num;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num;
		Fibo(num);
		cout << endl;
	}
	return 0;
}
