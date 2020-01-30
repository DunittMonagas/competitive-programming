
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                UVa 10141 - Request for Proposal               *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

int main(){

	int r, p, rm;
	double pre, m;
	char pro[85], nom[85];

	for(int t= 1;;t++){

		scanf("%d %d\n",&r,&p);
		if(r==0 && p==0) break;
		m= 1000000000.0;
		rm= -1;

		for(int i= 0; i<r; i++){
			gets(pro);
		}

		for(int i= 0; i<p; i++){

			gets(pro);
			scanf("%lf %d\n",&pre,&r);
			if(r>rm || (r==rm && pre<m)){
				m= pre;
				strcpy(nom,pro);
				rm= r;
			}
			for(int j= 0; j<r; j++){
				gets(pro);
			}

		}

		if(t>1) printf("\n");
		printf("RFP #%d\n",t);
		printf("%s\n",nom);

	}
	
	return 0;
}
