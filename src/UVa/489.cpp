
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 489 - Hangman Judge                  *
*****************************************************************
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

	long int n;
	int err;
	bool cambio, listo;
	string str, s;
	string aux, intentos;

	cin >> n;
	while(n != -1){

		cin >> str >> s;
		err = 7;
		listo= false;

		aux=  str;
		aux.replace(aux.begin(), aux.end(), str.size(), '0');
		intentos.clear();

		for(int i= 0; i<s.size(); i++){

			cambio= false;

			if(intentos.find(s[i]) == string::npos){

				intentos+= s[i];

				for(int j= 0; j<str.size(); j++){

					if(str[j] == s[i]){
						aux[j]= s[i];
						cambio= true;
					}

				}

			}else
				continue;

			if(aux == str){
				listo= true;
				break;
			}

			if(!cambio)
				--err;

			if(err <= 0)
				break;

		}

		if(listo){
			cout << "Round " << n << endl;
			cout << "You win." << endl;
		}else{
			if(!listo && err <= 0){
				cout << "Round " << n << endl;
				cout << "You lose." << endl;
			}else{
				if(!listo && err > 0){
					cout << "Round " << n << endl;
					cout << "You chickened out." << endl;
				}
			}
		}
		
		cin >> n;
	}

	return 0;
}