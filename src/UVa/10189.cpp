
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 10189 - Minesweeper                    *
*****************************************************************
*/

#include <cstdio>
#include <vector>
using namespace std;

int main(){

	int n, m, c=1;
	char b;

	scanf("%d %d",&n,&m);
	scanf("%c",&b);

	while(n!=0 && m!=0){

		vector < vector <char> > A(n,vector <char>(m,'.'));
		vector < vector <int> > B(n,vector <int>(m,0));

		for(int i= 0;i<n;i++){
			for(int j= 0;j<m;j++){
				scanf("%c",&A[i][j]);
				if(A[i][j]=='*'){
					B[i][j]= -1;
					if((i-1)>=0 && B[i-1][j]!=-1) B[i-1][j]++;
					if((i-1)>=0 && (j+1)<m && B[i-1][j+1]!=-1) B[i-1][j+1]++;
					if((j+1)<m && B[i][j+1]!=-1) B[i][j+1]++;
					if((i+1)<n && (j+1)<m && B[i+1][j+1]!=-1) B[i+1][j+1]++;
					if((i+1)<n && B[i+1][j]!=-1) B[i+1][j]++;
					if((i+1)<n && (j-1)>=0 && B[i+1][j-1]!=-1) B[i+1][j-1]++;
					if((j-1)>=0 && B[i][j-1]!=-1) B[i][j-1]++;
					if((i-1)>=0 && (j-1)>=0 && B[i-1][j-1]!=-1) B[i-1][j-1]++;
				}
			}
			scanf("%c",&b);
		}

		if(c>1) printf("\n");
		printf("Field #%d:\n",c++);

		for(int i= 0;i<n;i++){
			for(int j= 0;j<m;j++){
				if(B[i][j]!=-1 ? printf("%d",B[i][j]):printf("*"));
			}
			printf("\n");
		}
		scanf("%d %d",&n,&m);
		scanf("%c",&b);

	}

	return 0;
}
