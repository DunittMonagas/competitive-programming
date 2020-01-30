
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 10945 - Mother bear                    *
*****************************************************************
*/

#include <cstdio>
#include <cstring>
#include <cctype>

char str[2048];

int main(){

	int i, j;
	bool pal;
	fgets(str, 2048, stdin);

	while(strcmp(str, "DONE\n") != 0){
		
		i= 0;
		j= strlen(str) - 2;
		pal= true;

		while(i < j){

			if(str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?' || str[i] == ' '){
				++i;
				continue;
			}

			if(str[j] == '.' || str[j] == ',' || str[j] == '!' || str[j] == '?' || str[j] == ' '){
				--j;
				continue;
			}

			if(tolower(str[i]) == tolower(str[j])){

				++i;
				--j;
				continue;

			}else{

				pal= false;
				break;

			}
		}

		printf("%s\n", (pal == true) ? "You won't be eaten!" : "Uh oh..");

		fgets(str, 2048, stdin);

	}

	return 0;
}