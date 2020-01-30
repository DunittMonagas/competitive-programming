
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*            UVa 499 - What's The Frequency, Kenneth?           *
*****************************************************************
*/

#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

int A[128];

int main(){

	ios::sync_with_stdio();
	cin.tie(0);

	int m= -1;
	string r, str;

	while(getline(cin, str)){

		for(int i= 0; i<str.size(); ++i)
			if(isalpha(str[i]))
				m= max(m, ++A[str[i]]);
			

		for(int i= 0; i<128; ++i)
			if(A[i] == m)
				r+= (char)i;

		sort(r.begin(), r.end());
		cout << r << " " << m << "\n";

		m= -1;
		r.clear();
		fill(A, A+128, 0);

	}

	return 0;
}