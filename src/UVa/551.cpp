
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              UVa 551 - Nesting a Bunch of Brackets            *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char str[3010];

int main(){

	bool f;
	int n, i, cont;

	while(fgets(str, 3010, stdin) && str[0] != '\0'){

		f= true;
		cont=  0;
		stack<char> P;

		n= strlen(str);
		for(i= 0; i<n && f; ++i){

			switch(str[i]){

				case '(':

					if(i+1<n && str[i+1] == '*'){
						P.push('(');
						P.push('*');
						++i;
						++cont;
					}else
						P.push(str[i]);

					break;

				case '[':
				case '{':
				case '<':

					P.push(str[i]);
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

				case '}':
					if(!P.empty() && P.top() == '{')
						P.pop();
					else
						f= false;

					break;

				case '>':
					if(!P.empty() && P.top() == '<')
						P.pop();
					else
						f= false;

					break;

				case '*':
					if(i+1<n && str[i+1] == ')')
						if(!P.empty() && P.top() == '*'){
							P.pop();
							P.pop();
							++i;
							++cont;
						}else
							f= false;
				
					break;

				default:
					break;

			}

		}

		(f && P.empty() ? printf("YES\n") : printf("NO %d\n", i-cont));

	}

	return 0;
}