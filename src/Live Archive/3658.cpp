
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              Live Archive 3658 - Report Recovery              *
*****************************************************************
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define NUM "0123456789"

//////////////////////PRODUCTO/////////////////////////
#define CANT_PRODUCTO 999                          //
///////////////////TOTAL CLIENTE///////////////////////
#define LIMITE_CLIENTE 4                             //
//////////////////////TOTAL////////////////////////////
#define LIMITE_SUMA_TOTAL 5                          //
///////////////////////////////////////////////////////

vvi result;
int fil, col;
vs num, nomb;
bool solucion;
vi temp, sum, resto, longt;

void GenerarFila(int fila, int columna, int lim, int ini, int cant, int total){

	if (solucion)
		return;

	if (columna == 0){
		
		int aux = stoi(num[fila].substr(num[fila].size() - longt[fila]));

		if (aux > total)
			return;

		result[fila][col - 1] = aux;
		resto[fila] = num[fila].size() - longt[fila];
	}

	if (columna == col - 1){

		if (sum[fila] == result[fila][col - 1] && resto[fila] == 0){

			bool continuar = true;

			if (fila != fil - 1)
				for (int k = 0; k < col; ++k){
					temp[k] += result[fila][k];
					if (temp[k] > result[fil - 1][k])
						continuar = false;
				}

			if (continuar){
				int sig = fila - 1;
				if (sig >= 0)
					for (longt[sig] = 1; longt[sig] <= LIMITE_CLIENTE; ++longt[sig])
						GenerarFila(sig, 0, longt[sig], 0, CANT_PRODUCTO, CANT_PRODUCTO*col);
						
				else
					for (sig = 0, solucion = true; solucion && sig < col; ++sig)
						if (temp[sig] != result[fil - 1][sig])
							solucion = false;
			}

			if (fila != fil - 1)
				for (int k = 0; k < col; ++k)
					temp[k] -= result[fila][k];

			return;

		}

	}else{
		if (num[fila][ini] == '0'){

			if (solucion)
				return;

			result[fila][columna]= 0;
			--resto[fila];
			GenerarFila(fila, columna + 1, lim, ini + 1, cant, total);
			++resto[fila];

		}else{

			for (int i = min(lim, resto[fila]); i > 0; --i){

				if (solucion)
					return;

				if(ini >= num[fila].size())
					continue;

				int aux = stoi(num[fila].substr(ini, i));

				if (fila != fil - 1 && columna != col - 1 && aux > cant)
					continue;

				if (aux > result[fila][col - 1])
					continue;

				if (sum[fila] + aux > result[fila][col - 1])
					continue;

				if(fila != fil -1 && temp[columna] + aux > result[fil-1][columna])
						continue;

				result[fila][columna] = aux;
				sum[fila] += aux;
				resto[fila] -= i;
				GenerarFila(fila, columna + 1, lim, ini + i, cant, total);
				sum[fila] -= aux;
				resto[fila] += i;
			}
		}
	}
}

void Iniciar(){
	
	solucion = false;
	sum = vi(5, 0);
	temp = vi(6, 0);
	resto = vi(5, 0);
	longt = vi(5, 0);
	num = vs(5, string());
	nomb = vs(5, string());
	result = vvi(5, vi(6, 0));

}

int main(){

	int t, i;
	size_t enc;
	string str;

	cin >> t;
	for (i = 0; i < t; ++i){

		Iniciar();
		fil = col = 1;

		cin >> str;
		for (enc = str.find_first_of(NUM); enc != string::npos; ++col){
			cout << "P" << col << " ";
			if (isdigit(str[enc + 1]))
				++enc;
			enc = str.find_first_of(NUM, enc + 1);
		}
		cout << "Totals" << endl;

		cin >> str;

		for (enc = str.find_first_of(NUM); str[0] != 'T' || str[1] != 'P'; ++fil){
			nomb[fil - 1] = str.substr(0, enc);
			num[fil - 1] = str.substr(enc);
			cin >> str;
			enc = str.find_first_of(NUM);
		}

		nomb[fil - 1] = str.substr(0, enc);
		num[fil - 1] = str.substr(enc);

		for (longt[fil-1] = 1; longt[fil-1] <= LIMITE_SUMA_TOTAL; ++longt[fil-1])
			GenerarFila(fil - 1, 0, longt[fil-1], 0, CANT_PRODUCTO*fil, CANT_PRODUCTO*fil*col);
		
		for (int j = 0; j < fil; ++j){
			cout << nomb[j];
			for (int k = 0; k < col; ++k)
				cout << " " << result[j][k];
			cout << endl;
		}

	}

	return 0;
}