#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	string a, b;
	cin >> a >> b;
	while(a.compare("*")!=0 && b.compare("*")!=0){
		int c= 0;
		for(unsigned int i= 0;i<a.size();i++)
				if(a[i]!=b[i] && a[i+1]==b[i+1]) c++;
		printf("%d\n",c);
		cin >> a >> b;
	}
	return 0;
}
