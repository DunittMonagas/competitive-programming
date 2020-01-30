
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 454 - Anagrams                       *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){

	int n;
	string str, aux;
	vector <string> r;
	map <string, vector<string> > A;
	map <string, vector<string> >::iterator it;

	ios::sync_with_stdio(false);
	
	cin >> n;
	cin.get();
	getline(cin, str);

	for(int i= 0; i<n; i++){

		while(true){

			getline(cin, str);
			if(str == "")
				break;

			aux= str;

			size_t pos= aux.find(" ");
			while(pos != string::npos){

				aux.erase(pos, 1);
				pos= aux.find(" ");

			}
			
			sort(aux.begin(), aux.end());

			it= A.find(aux);
			if(it != A.end()){

				int t= it->second.size();
				for(int k= 0; k<t; k++)
					if(it->second[k] < str)
						r.push_back(it->second[k] + " = " + str);
					else
						r.push_back(str + " = " + it->second[k]);

				it->second.push_back(str);

			}else{

				A.insert(pair<string, vector<string> > (aux, vector<string> (1, str)));

			}
			

		}

		sort(r.begin(), r.end());

		for(int j= 0; j<r.size(); j++)
			cout << r[j] << endl;

		if(i+1 != n)
			cout << endl;

		r.clear();
		A.clear();

	}

	return 0;
}