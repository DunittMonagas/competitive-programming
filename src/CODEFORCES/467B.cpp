
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*             Codeforce 467B - Fedor and New Game               *
*****************************************************************
*/

#include <iostream>
#include <bitset>

using namespace std;

int J[1010];

bool Diferencia(int a, int b, int t){

	int cont= 0;
	bitset<25> BitA (a);
	bitset<25> Bitb (b);

	for(int i= 24; i>=0; --i)
		if(BitA[i] != Bitb[i])
			++cont;

	return cont > t ? true:false;

}

int main(){

	int n, m, k, cont= 0;

	cin >> n >> m >> k;

	for(int i= 0; i<= m; ++i)
		cin >> J[i+1];

	for(int i= 1; i<=m; ++i)
		if(!Diferencia(J[i], J[m+1], k))
			++cont;
	
	cout << cont << "\n";

	return 0;
}