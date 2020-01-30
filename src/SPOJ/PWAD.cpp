#include <iostream>
using namespace std;
int main(){
	int n, m, xds, xdi, xis, xii, ydi;
	cin >> n;
	m=n/2;
	xds=m+1; xdi=m+1; ydi=n-2;
	xis=m-1;  xii=m+1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==m){
				cout << "*";
			}else{
				if(j==m){
					cout << "*";
				}else{
					if(j==xds && i==xds-m){
						cout << "*";
						xds++;
					}else{
						if(j==xis && i==m-xis ){
							cout << "*";
							xis--;
						}else{
							if(i==xdi && j==ydi){
								cout << "*";
								ydi--;
								xdi++;
							}else{
								if(i==xii && j==xii-m){
									cout << "*";
									xii++;
								}else{
									cout << " ";
								}
							}
						}
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}
