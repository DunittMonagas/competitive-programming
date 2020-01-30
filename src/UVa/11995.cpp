
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*           UVa 11995 - I Can Guess the Data Structure!         *
*****************************************************************
*/

#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main(){

	int n, t, x;
	bool pl, cl, cp;

	while(scanf("%d", &n) != EOF){

		queue<int> C;
		stack<int> P;
		priority_queue<int> CP;

		pl= cl= cp= true;
		for(int i= 0; i<n; ++i){

			scanf("%d %d", &t, &x);

			if(pl || cl || cp)
				if(t == 1){

					C.push(x);
					P.push(x);
					CP.push(x);

				}else{

					if(pl && !P.empty() && P.top() == x)
						P.pop();
					else
						pl= false;
						
					if(cl && !C.empty() && C.front() == x)
						C.pop();
					else
						cl= false;

					if(cp && !CP.empty() && CP.top() == x)
						CP.pop();
					else
						cp= false;

				}

		}

		if(pl && !cl && !cp)
			printf("stack\n");
		else
			if(!pl && cl && !cp)
				printf("queue\n");
			else
				if(!pl && !cl && cp)
					printf("priority queue\n");
				else
					if(!pl && !cl && !cp)
						printf("impossible\n");
					else
						printf("not sure\n");

	}

	return 0;
}