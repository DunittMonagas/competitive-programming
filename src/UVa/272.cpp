
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                       UVa 272 - TEX Quotes                    *
*****************************************************************
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
		
	string str;
	size_t pos;
	bool com= false;

	ios::sync_with_stdio(false);

	while(getline(cin, str)){

		pos= str.find("\"");
		while(pos != string::npos){

			str.replace(pos, 1, (com ? "''" : "``"));
			com= !com;

			pos= str.find("\"", pos+2);
		}

		cout << str << endl;

	}

	return 0;
}