
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                   UVa 11926 - Multitasking                    *
*****************************************************************
*/

#include <cstdio>
#include <bitset>

using namespace std;

#define MAX 1000000

bool Tarea(int st, int ed, bitset<MAX+100> *F){

	for(; st<=ed; ++st)
		if(F->test(st))
			return false;
		else
			F->set(st);
	
	return true;

}

bool Tarea(int st, int ed, int rt, bitset<MAX+100> *F){

	for(; st<MAX; st+= rt, ed= min(ed + rt, MAX))
		for(int aux= st+1; aux<=ed; ++aux)
			if(F->test(aux))
				return false;
			else
				F->set(aux);
	
	return true;

}

int main(){

	bool val;
	int n, m, st, ed, rt;

	scanf("%d %d", &n, &m);
	while(n != 0 || m != 0){

		val = true;
		bitset<MAX + 100> F;
		
		for(int i= 0; i<n; ++i){

			scanf("%d %d", &st, &ed);

			if(val)
				val= Tarea(st+1, ed, &F);
			
		}

		for(int i= 0; i<m; ++i){

			scanf("%d %d %d", &st, &ed, &rt);

			if(val)
				val= Tarea(st, ed, rt, &F);

		}

		(val ? printf("NO CONFLICT\n") : printf("CONFLICT\n"));
		scanf("%d %d", &n, &m);

	}

	return 0;
}