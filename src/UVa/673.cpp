
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 673 - Parentheses Balance                *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char str[130];

int main(){

	bool f;
	int t, n;

	scanf("%d\n", &t);

	for(int i= 0; i<t; ++i){

		fgets(str, 130, stdin);

		f= true;
		stack<char> P;

		n= strlen(str);
		for(int j= 0; j<n && f; ++j){

			switch(str[j]){

				case '(':
				case '[':

					P.push(str[j]);
					break;

				case ')':
					
					if(!P.empty() && P.top() == '(')
						P.pop();
					else
						f= false;					
					break;

				case ']':
					
					if(!P.empty() && P.top() == '[')
						P.pop();
					else
						f= false;
					break;

				default:
					break;
			};

		}

		(f && P.empty() ? printf("Yes\n") : printf("No\n"));

	}

	return 0;
}