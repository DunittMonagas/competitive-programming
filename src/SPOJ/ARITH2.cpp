#include <cstdio>
#include <cstring>
int main(){
	long long int a, n, m;
	char str;
	scanf("%lld\n\n",&a);
	for(int i= 0; i<a; i++){
		scanf("%lld %c ",&n,&str);
		while(str!='='){
			scanf("%lld ",&m);
			if(str=='+'){
				n+= m;
			}else{
				if(str=='-'){
					n-= m;
				}else{
					if(str=='*'){
						n*= m;
					}else{
						if(str=='/'){
							n/= m;
						}
					}
				}
			}
			scanf("%c ",&str);
		}
		printf("%lld\n",n);
		scanf("\n");
	}
	return 0;
}
