
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                     UVa 156 - Ananagrams                      *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	map <string, pair<string, long long int> > Dic;
	map <string, pair<string, long long int> >:: iterator it;
	vector <string> r;
	string str, stro;

	ios::sync_with_stdio(false);

	cin >> str;
	

	while(str != "#"){

		stro.resize(str.size());
		transform(str.begin(), str.end(), stro.begin(), ::tolower);
		sort(stro.begin(), stro.end());

		it= Dic.find(stro);
		if(it == Dic.end()){
			Dic.insert(pair<string, pair<string, long long int> >(stro, pair<string, long long int> (str, 1)));
		}else
			it->second.second++;

		cin >> str;

	}

	for(it= Dic.begin(); it!= Dic.end(); it++)
		if(it->second.second == 1)
			r.push_back(it->second.first);

	sort(r.begin(), r.end());

	for(int i= 0; i<r.size(); i++)
		cout << r[i] << endl;


	return 0;
}