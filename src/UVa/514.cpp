
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                        UVa 514 - Rails                        *
*****************************************************************
*/

#include <cstdio>
#include <stack>

using namespace std;

int E[1005];

bool Posible(int n){

	bool p= true;
	stack<int> S;
	int i= 0, j= 1;

	while(p && i<n){

		while(j < E[i])
			S.push(j++);

		if(j <= n && E[i] == j){
			++i;
			++j;
			continue;
		}

		if(E[i] < j && E[i] == S.top()){
			++i;
			S.pop();
		}else
			p= false;

	}

	return p;

}

int main(){

	int n;
	bool f;

	scanf("%d", &n);

	while(n != 0){

		f= false;
		while(!f){
		
			for (int i= 0; i<n && !f; ++i){
				scanf("%d", &E[i]);
				if(!i && !E[i])
					f= true;
			}

			if(!f)
				(Posible(n) ? printf("Yes\n") : printf("No\n"));
			
		}

		printf("\n");

		scanf("%d", &n);

	}

	return 0;
}