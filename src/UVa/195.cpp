
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 195 - Anagram                        *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Comparacion(char x, char y){
	
	if (tolower(x) == tolower(y)) 
		return (x < y); 
	else 
		return (tolower(x) < tolower(y)); 

}


int main(){

	int n;
	string str;

	ios::sync_with_stdio(false);

	cin >> n;

	for(int i= 0; i<n; i++){

		cin >> str;
		sort(str.begin(), str.end(), Comparacion);

		do{
			cout << str << endl;
		}while(next_permutation(str.begin(), str.end(), Comparacion));

	}

	return 0;
}