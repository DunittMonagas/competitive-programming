
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 630 - Anagrams (II)                    *
*****************************************************************
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int t, np;
	string str, aux;

	cin >> t;

	for(int i= 0; i<t; ++i){

		cin >> np;

		map<string, vector<string> >Dic;
		map<string, vector<string> >::iterator it;

		for(int j= 0; j<np; ++j){

			cin >> str;
			aux= str;
			sort(aux.begin(), aux.end());

			Dic[aux].push_back(str);

		}

		while(cin >> str && str != "END"){

			aux= str;
			sort(aux.begin(), aux.end());

			cout << "Anagrams for: " << str << "\n";

			it= Dic.find(aux);
			if(it != Dic.end())
				for(int j= 0; j<it->second.size(); ++j)
					cout << "  " << j+1 << ") " << it->second[j] << "\n";
			else
				cout << "No anagrams for: " << str << "\n";

		}

		if(i+1 != t)
			cout << "\n";

	}

	return 0;
}