
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 11559 - Event Planning                   *
*****************************************************************
*/

#include <cstdio>

int main(){

	int p, pres, h, s, prec, c, aux= 1000000000;

	while(scanf("%d %d %d %d",&p,&pres,&h,&s)!=-1){
		
		for(int i= 0; i<h; i++){
			scanf("%d",&prec);
			for(int j= 0; j<s; j++){
				scanf("%d",&c);
				if(p<c && p*prec<=pres && p*prec<aux) aux= p*prec;
			}
		}

		if(aux==1000000000 ? printf("stay home\n"):printf("%d\n",aux));
		aux=1000000000;
	}

	return 0;
}
