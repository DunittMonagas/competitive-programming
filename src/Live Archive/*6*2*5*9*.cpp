
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              Live Archive 6259 - Word equations               *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<bool, vector<string> > bv;

string T;
int R[1000000];
map<string, bv > E;
char str[2010], P[1000000];

void Resolver(const string &cl){

	map<string, bv >::iterator it= E.find(cl);

	if(it->second.first)
		T.insert(0, it->second.second[0]);
	else
		for(int i= it->second.second.size()-1; i>=0; --i)
			Resolver(it->second.second[i]);

}

int main(){

	char *p;
	size_t enc;
	int t, k, cont, n;

	scanf("%d", &t);

	T.reserve(1000000);

	for(int i= 0; i<t; ++i){

		scanf("%d\n", &k);

		map<string, bv >::iterator it;

		for(int j= 0; j<k; ++j){

			fgets(str, 2010, stdin);
			str[strlen(str)-1]= '\0';

			p= strtok(str, " ");
			
			cont= 0;
			string aux;
			vector<string> pal;
			while(p != NULL){

				if(!cont)
					aux= string(p);
				else
					if(p[0] == '=' || p[0] == '+'){
						p= strtok(NULL, " ");
						continue;
					}else
						pal.push_back(string(p));

				p= strtok(NULL, " ");

				cont++;

			}

			E[aux]= (islower(pal[0][0]) ? bv(true, pal) : bv(false, pal));

		}

		scanf("%s\n", str);
		scanf("%s\n", P);

		n= strlen(P);
		Resolver(str);

		enc= T.find(P[0]);
		for(int j= 1; j<n && enc != string::npos; ++j)
			enc= T.find(P[j], enc+1);

		(enc != string::npos ? printf("YES\n"):printf("NO\n"));		

		T.clear();
		for(it= E.begin(); it != E.end(); ++it)
			it->second.second.clear();
		E.clear();
	}

	return 0;
}