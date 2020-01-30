
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 401 - Palindromes                    *
*****************************************************************
*/

#include <cstdio>
#include <cstring>


char str[2048];

int main(){

	int i, j;
	bool pal, esp;

	while(fgets(str, 2048, stdin)){

		i= 0;
		j= strlen(str) - 2;
		pal=esp= true;

		while(i <= j){

			if((str[i] == 'E' && str[j] == '3') || (str[i] == '3' && str[j] == 'E')){

				++i;
				--j;
				pal= false;
				continue;

			}

			if((str[i] == 'J' && str[j] == 'L') || (str[i] == 'L' && str[j] == 'J')){

				++i;
				--j;
				pal= false;
				continue;

			}

			if((str[i] == 'S' && str[j] == '2') || (str[i] == '2' && str[j] == 'S')){

				++i;
				--j;
				pal= false;
				continue;

			}

			if((str[i] == 'Z' && str[j] == '5') || (str[i] == '5' && str[j] == 'Z')){

				++i;
				--j;
				pal= false;
				continue;

			}

			if(str[i] == str[j]){
				
				if(esp && str[i]== 'A' || str[i]== 'H' || str[i]== 'I' || str[i]== 'M' || str[i]== 'O' || str[i]== 'T' || str[i]== 'U' ||str[i]== 'V' || 
					str[i]== 'W' || str[i]== 'X' || str[i]== 'Y' || str[i]== '1' || str[i]== '8'){

					++i;
					--j;
					continue;

				}

				esp= false;
				
				++i;
				--j;

			}else{

				pal= esp= false;
				break;

			}

		} 

		str[strlen(str)-1]= '\0';

		if(!pal && !esp)
			printf("%s -- is not a palindrome.\n\n", str);
		else
			if(pal && !esp)
				printf("%s -- is a regular palindrome.\n\n", str);
			else
				if(!pal && esp)
					printf("%s -- is a mirrored string.\n\n", str);
				else
					printf("%s -- is a mirrored palindrome.\n\n", str);

	}

	return 0;
}