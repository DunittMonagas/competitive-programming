
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*            UVa 11507 - Bender B. Rodríguez Problem            *
*****************************************************************
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, map<string,string> > A;	

int main(){

	long int n;
	string dir, dob;

/////////////////////////////////////////////////
	A["+x"]["+y"] = "+y";
	A["+x"]["-y"] = "-y";
	A["+x"]["+z"] = "+z";
	A["+x"]["-z"] = "-z";

	A["-x"]["+y"] = "-y";
	A["-x"]["-y"] = "+y";
	A["-x"]["+z"] = "-z";
	A["-x"]["-z"] = "+z";
/////////////////////////////////////////////////
	A["+y"]["+y"] = "-x";
	A["+y"]["-y"] = "+x";
	A["+y"]["+z"] = "+y";
	A["+y"]["-z"] = "+y";

	A["-y"]["+y"] = "+x";
	A["-y"]["-y"] = "-x";
	A["-y"]["+z"] = "-y";
	A["-y"]["-z"] = "-y";
/////////////////////////////////////////////////
	A["+z"]["+y"] = "+z";
	A["+z"]["-y"] = "+z";
	A["+z"]["+z"] = "-x";
	A["+z"]["-z"] = "+x";

	A["-z"]["+y"] = "-z";
	A["-z"]["-y"] = "-z";
	A["-z"]["+z"] = "+x";
	A["-z"]["-z"] = "-x";
/////////////////////////////////////////////////

	
	cin >> n;
	while(n != 0){

		dir = "+x";

		for(long int i=0; i<n-1; i++){
			
			cin >> dob;
			if(dob == "No")
				continue;

			dir = A[dir][dob];

		}

		cout << dir << endl;

		cin >> n;
	}

	return 0;
}