#include <cstdio>
#include <map>
using namespace std;
int main(){
	int n, num, marca=0;
	char str[6];
	map <int,int> c;
	map <int,int>::iterator it;
	scanf("%d\n" , &n);
	for(int i=0; i<n; i++){
		scanf("%s %d", str, &num);
		it= c.find(num);
		if(str[0]=='i'){
			if(it!=c.end()){
				int aux= it->second;
				it->second++;
				if(aux<2 && aux+1>1){
					marca++;
				}
			}else{
				c[num]++;
			}
		}else{
			if(it!=c.end()){
				int aux= it->second;
				it->second--;
				if(aux>1 && aux-1<2){
					marca--;
				}
				if(it->second<1){
					c.erase(it);
				}
			}
		}
		int tam= c.size();
		if(marca>0 && tam>1){
			printf("both\n");
		}else{
			if(marca>0){
				printf("homo\n");
			}else{
				if(tam>1){
					printf("hetero\n");
				}else{
					printf("neither\n");
				}
			}
		}
	}
	return 0;
}
