
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              Live Archive 6959 - Judging Troubles             *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main(){
	
	string str;
	int n, cont;

	while(cin >> n){

		cont= 0;
		map<string, int> A;
		map<string, int>::iterator it;

		for(int i= 0; i<n; ++i){

			cin >> str;
			it= A.find(str);

			if(it != A.end())
				it->second++;
			else
				A.insert(pair<string, int>(str, 1));

		}

		for(int i= 0; i<n; ++i){

			cin >> str;
			it= A.find(str);

			if(it != A.end() && it->second != 0){
				++cont;
				it->second--;
			}
			
		}

		cout << cont << "\n";

	}

	return 0;
}