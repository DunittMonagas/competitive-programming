
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*               UVa 11498 - Division of Nlogonia                *
*****************************************************************
*/

#include <cstdio>

int main(){

	int n, x, y, a, b;
	scanf("%d",&n);

	while(n!=0){

		scanf("%d %d",&x,&y);
		for(int i=0; i<n; i++){
			scanf("%d %d",&a,&b);
			if(a==x || b==y){
				printf("divisa\n");
			}else{
				if(a>x){
					if(b>y ? printf("NE\n"):printf("SE\n"));
				}else{
					if(b>y ? printf("NO\n"):printf("SO\n"));
				}
			}
		}
		scanf("%d",&n);

	}
	
	return 0;
}
