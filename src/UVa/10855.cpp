
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*   	           UVa 10855 - Rotated square                   *
*****************************************************************
*/

#include <cstdio>

int d1, d2;
char A[1000000];
char B[4][1000000];

void count(int *acc){

	bool c;
	int n= d1 - d2 + 1;
	for(int i= 0; i<n; ++i)
		for(int j= 0; j<n; ++j)
			for(int d= 0; d<4; ++d){

				c= true;
				for(int x= 0; c && x<d2; ++x)
					for(int y= 0; c && y<d2; ++y)
						c= (A[(i + x)*d1 + (j + y)] == B[d][x*d2 + y]);

				if(c) ++acc[d];

			}

}

void rotate(){

	for(int d= 0; d<3; ++d)
		for(int i= 0; i<d2; ++i)
			for(int j= 0; j<d2; ++j)
				B[d+1][i*d2 + j]= B[d][(d2 - j - 1)*d2 + i];

}

int main(){

	int acc[4];

	while(scanf("%d %d\n", &d1, &d2), (d1 || d2)){

		for(int i= 0; i<d1; ++i){
			for(int j= 0; j<d1; ++j)
				scanf("%c", &A[i*d1 + j]);
			scanf("\n");
		}

		for(int i= 0; i<d2; ++i){
			for(int j= 0; j<d2; ++j)
				scanf("%c", &B[0][i*d2 + j]);
			scanf("\n");
		}

		rotate();

		acc[0]= acc[1]= acc[2]= acc[3]= 0;
		count(acc);

		printf("%d %d %d %d\n", acc[0], acc[1], acc[2], acc[3]);

	}

	return 0;
}
