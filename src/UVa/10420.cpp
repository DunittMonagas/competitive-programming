
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 10420 - List of Conquests                 *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	int n;
	string str, aux;
	map<string, int> L;
	map<string, int>:: iterator it;

	cin >> n;
	cin.get();

	for(int i= 0; i<n; i++){

		cin >> str;
		getline(cin, aux);

		it= L.find(str);

		if(it != L.end())
			++it->second;
		else
			L.insert(pair<string, int> (str, 1));

	}

	for(it= L.begin(); it!=L.end(); ++it)
		cout << it->first << " " << it->second << endl;

}