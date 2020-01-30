#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Fenwick{
	private:
		vector <long long int> *T;
	public:
		Fenwick(vector <long long int> *A){
			T= new vector <long long int>(11,0);
			for(long int i= 0; i<A->size(); i++)
				T->at(A->at(i))= 1;
		}
		/*void Actualizar(long long int i, int v){
			for(; i<T->size(); i+=LowBit(i))
				T->at(i)+= v;
		}*/
		long long int Suma(long int i){
			long long int aux= 0;
			for(;i>1; i-=LowBit(i))
				aux+= T->at(i);
			return aux;
		}
		long long int Suma(long int i, long int j){
			return i>1 ? Suma(j)-Suma(i-1):Suma(j);
		}
		long int Tam(){
			return T->size();
		}
	private:
		int LowBit(long long int i){
			return i & -i;
		}

};
int main(){
	long int t, n;
	long long int aux;
	scanf("%ld",&t);
	//printf("I %ld\n",t);
	//cin >> t;
//	cout << "t: " << t << endl; 
	for(long int i= 0; i<t; i++){
	//	cout << "i: " << i << endl;
	//	cin >> n;
		scanf("%ld",&n);
	//	cout << "n: " << n << endl;
	//	printf("I 2 %ld\n",n);
		vector <long long int> *P= new vector <long long int>();
		for(long int j= 0; j<n; j++){
	//		cout << "j: " << j << endl;
	//		cin >> aux;
			scanf("%lld",&aux);
	//		cout << "aux: " << aux << endl;
	//		printf("Isub %lld\n",aux);
			P->push_back(aux);
		}
		aux= 0;
		Fenwick *F= new Fenwick(P);
		vector <long long int>::iterator it;
		for(it= P->begin(); it!=P->end(); it++)
			aux+= F->Suma(*it+1,F->Tam()-1);
		printf("%lld\n",aux);
	}
	return 0;
}