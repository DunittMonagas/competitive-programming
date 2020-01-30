#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main(){
	int n, g1, g2, mayor=0;
	string C, A, B;
	map<string,int> t;
	map<string,int>::iterator it;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<16; j++){
			cin >> A >> B >> g1 >> g2;
			if(g1>g2){
				it= t.find(A);
				if(it!=t.end()){
					it->second++;
					if(it->second>mayor){
						 mayor= it->second;
						 C= it->first;
					 }
				}else{;
					t[A]++;
				}
			}else{
				it= t.find(B);
				if(it!=t.end()){
					it->second++;
					if(it->second>mayor){
						 mayor= it->second;
						 C= it->first;
					 }
				}else{
					t[B]++;
				}
			}
		}
		t.clear();
		mayor=0;
		cout << C << endl;
	}
	return 0;
}
