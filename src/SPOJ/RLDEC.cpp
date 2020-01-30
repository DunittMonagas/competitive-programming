
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 SPOJ RLDEC - Run Length Decoding              *
*****************************************************************
*/

#include <string>
#include <iostream>

using namespace std;


int main(){

	int t;
	bool one;
	string str, reslt;

	cin >> t;
	cin.ignore();
	for(int i = 0; i < t; ++i){

		reslt = "";
		one = false;
		
		getline(cin, str);
		for (int j = 0; j < str.size(); ++j){
			
			if(isdigit(str[j])){

				if(str[j] != '1'){

					if(one)
						reslt += str[j];
					else{
						reslt.append(str[j] - '0', str[j + 1]);
						++j;
					}

				}else{
					
					if(!one)
						one = !one;
					else if(j + 1 < str.size() && str[j + 1] == '1'){

						reslt += '1';
						++j;

					}else
						one = false;

				}
				
			}else
				reslt += str[j];


		}

		cout << reslt << "\n";

	}

	return 0;

}
