#include <iostream>
#include <string>
using namespace std;
void letras(string str){
	int   voc=0;
	for(unsigned int i=0; i<str.length(); i++){
		if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='i' || str[i]=='I' || str[i]=='o' || str[i]=='O' || str[i]=='u' || str[i]=='U'){
			voc++;
		}
	}
	cout << voc << "/" << str.length() <<  endl;
}
int main(){
	string str;
	while(getline (cin,str)){
		letras(str);
	}
	return 0;
}
