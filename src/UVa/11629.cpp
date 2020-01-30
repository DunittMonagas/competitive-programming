
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                UVa 11629 - Ballot evaluation                  *
*****************************************************************
*/

#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

int main(){

	bool f;
	char str[50];
	int p, g, aux, aux2;

	while(scanf("%d %d", &p, &g) != EOF){

		map<string, int> A;

		for(int i= 0; i<p; ++i){
			scanf("%s %d.%d", str, &aux, &aux2);
			A[str]= aux*10 + aux2;
		}

		for(int i= 0; i<g; ++i){

			aux= 0.0;
			while(scanf("%s", str) && (str[0] == '+' || isalnum(str[0])))
				if(str[0] != '+')
					aux+= A[str];

			scanf("%d", &aux2);

			aux2*= 10;

			if(strcmp(str, "<") == 0)
				f= (aux < aux2);
			else
				if(strcmp(str, ">") == 0)
					f= (aux > (int)aux2);
				else
					if(strcmp(str, "<=") == 0)
						f= (aux <= aux2);
					else
						if(strcmp(str, ">=") == 0)
							f= (aux >= (int)aux2);
						else
							f= (aux == aux2);
						
			printf("Guess #%d was %s.\n", i+1, (f ? "correct":"incorrect"));

		}

	}

	return 0;
}