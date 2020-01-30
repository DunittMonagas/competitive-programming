
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 11727 - Cost Cutting                   *
*****************************************************************
*/

#include <cstdio>

int main(){

	int n, a, b, c;
	scanf("%d",&n);

	for(int i=0; i<n; i++){

		scanf("%d %d %d",&a,&b,&c);
		if((a>b && a<c) || (a>c && a<b)) printf("Case %d: %d\n",i+1,a);
		if((b>a && b<c) || (b>c && b<a)) printf("Case %d: %d\n",i+1,b);
		if((c>a && c<b) || (c>b && c<a)) printf("Case %d: %d\n",i+1,c);

	}
	
	return 0;
}
