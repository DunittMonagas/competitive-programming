
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  Live Archive 6500 - Boxes                    *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

bool Tab[101][101];

int main(){

	int n, m, t, cont;

	scanf("%d", &t);

	for(int i= 0; i<t; ++i){

		cont= 0;
		scanf("%d %d", &n, &m);

		for(int f= 0; f<n; ++f)
			for(int c= 0; c<m; ++c)
				scanf("%d", &Tab[f][c]);

		for(int c= 0; c<m; ++c)
			for(int f= n-1; f>=0; --f)
				if(!Tab[f][c])
					for(int k= f-1; k>=0; --k)
						if(Tab[k][c]){
							cont+= f - (k+1) + 1;
							Tab[k][c]= false;
							Tab[f][c]= true;
							--f;
						}

		printf("%d\n", cont);

		memset(Tab, false, sizeof(Tab));
	}

	return 0;
}