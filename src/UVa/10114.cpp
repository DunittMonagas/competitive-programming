
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 10114 - Loansome Car Buyer               *
*****************************************************************
*/

#include <cstdio>

int main(){

	int a, m, mdp, contm;
	double pi, pre, vc, aux;
	scanf("%d %lf %lf %d",&m,&pi,&pre,&mdp);

	while(m>0){

		double *dp= new double[m+1];
		for(int i= 0; i<mdp;i++){

			scanf("%d %lf",&a,&aux);
			for(int j= a; j<m;j++){
				dp[j]= aux;
			}

		}

		aux= pi+pre;
		vc= aux-dp[0]*aux;
		aux= pre/m;
		contm= 0;
		while(vc<pre){

			vc*= 1-dp[++contm];
			pre-=aux;

		}

		scanf("%d %lf %lf %d",&m,&pi,&pre,&mdp);
		if(contm==1 ? printf("1 month\n"):printf("%d months\n",contm));

	}

	return 0;
}
