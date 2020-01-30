
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                UVa 11111 - Generalized Matrioshkas            *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <utility>

using namespace std;

#define TAM 10000000

typedef pair<long long int, long long int> ll;

char str[TAM];

int main(){

	bool f;
	char *p;
	long long int num, pri;

	while(fgets(str, TAM, stdin)){
		
		stack<ll> P;

		f= true;
		p= strtok(str, " ");
		pri= abs(atol(p));

		while(p != NULL && f){

			num= atoi(p);
			if(!num)
				break;

			if(!P.empty() && num == -P.top().first){

				P.pop();
				if(!P.empty())
					if(P.top().second + num < abs(P.top().first))				
							P.top().second+= num;
					else
						f= false;

			}else
				if(num < 0)
					P.push(ll(num, 0));
				else
					f= false;

			p= strtok(NULL, " ");

		}

		(f && P.empty() ? printf(":-) Matrioshka!\n") : printf(":-( Try again.\n"));

	}

	return 0;
}