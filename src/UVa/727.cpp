
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 727 - Equation                       *
*****************************************************************
*/

#include <cstdio>
#include <cctype>
#include <stack>

using namespace std;

int Pre[]= {3, 2, 0, 2, 0, 3, 0};

int main(){

	int t;
	bool r;
	char l[5];
	stack<char> P;

	scanf("%d\n", &t);

	for(int i= 0; i<t; ++i){

		while(fgets(l, 5, stdin) && l[0] != '\n'){

			if(isdigit(l[0])){
				printf("%c", l[0]);
				continue;
			}

			if(l[0] == '('){
				P.push(l[0]);
				continue;
			}

			if(l[0] == ')'){

				while(!P.empty() && P.top() != '('){
					printf("%c", P.top());					
					P.pop();
				}

				P.pop();
				continue;

			}

			do{

				r= false;

				if(P.empty() || P.top() == '('){
					P.push(l[0]);
					break;
				}

				if(Pre[l[0] - '*'] < Pre[P.top() - '*']){
					printf("%c", P.top());
					P.pop();
					r= true;
					continue;		
				}

				if(Pre[l[0] - '*'] > Pre[P.top() - '*'])
					P.push(l[0]);
				else{
					printf("%c", P.top());
					P.pop();
					P.push(l[0]);
				}				

			}while(r);

		}

		while(!P.empty()){
			printf("%c", P.top());
			P.pop();
		}

		printf("\n");

		if(i+1 != t)
			printf("\n");

	}

	return 0;
}