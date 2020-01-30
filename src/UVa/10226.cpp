
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 10226 - Hardwood Species                  *
*****************************************************************
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

	string str;
	int t, cont;

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(4);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> t;
	cin.get();
	cin.get();

	for(int i= 0; i<t; ++i){

		map<string, int> B;
		map<string, int>::iterator it;

		cont= 0;
		while(getline(cin, str) && str.size()){
			++cont;
			++B[str];
		}	
		
		for(it= B.begin(); it != B.end(); ++it)
			cout << it->first << " " << ((float)it->second*100.0)/(float)cont << "\n";

		if(i+1 != t)
			cout << endl;

	}

	return 0;
}