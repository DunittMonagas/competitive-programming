#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	int a, b;
	string c;
	map <string,int> m;
	map <string,int>::iterator it;
	scanf("%d %d",&a,&b);
	for(int i= 0;i<a;i++){
		cin >> c;
		m[c]++;
	}
	for(it= m.begin();it!=m.end();it++)
		cout << it->second << endl;
	return 0;
}
