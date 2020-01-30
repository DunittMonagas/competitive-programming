#include <cstdio>
#include <queue>
using namespace std;
int main(){
	int a, b, c , d, aux;
	bool f;
	scanf("%d\n",&a);
	for(int i= 0; i<a; i++){
		priority_queue <int> V;
		f= false;
		scanf("%d %d %d\n",&b,&c,&d);
		for(int j= 0;j<b; j++){
			scanf("%d\n",&aux);
			V.push(aux);
		}
		for(int j= 0; j<c; j++){
			aux= V.top();
			V.pop();
			aux-= d;
			if(aux > 0){
				V.push(aux);
			}else{
				f= true;
				break;
			}
		}
		if(f ? printf("NO\n"):printf("YES\n"));
	}
	return 0;
}