
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 146 - ID Codes                       *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	string str, aux;

	cin >> str;

	while(str != "#"){

		aux= str;
		sort(aux.begin(),aux.end());
		next_permutation(str.begin(),str.end());
		cout << (aux==str ? "No Successor\n":str + "\n");
		cin >> str;

	}
	return 0;
}