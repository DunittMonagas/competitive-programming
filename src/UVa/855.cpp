
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                   UVa 855 - Lunch in Grid City                *
*****************************************************************
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int t, s, a, f, x, y;

	scanf("%d", &t);

	for (int i= 0; i<t; ++i){
		
		vector<int> A, B;

		scanf("%d %d %d", &s, &a, &f);
		for(int j= 0; j<f; ++j){

			scanf("%d %d", &x, &y);
			A.push_back(x);
			B.push_back(y);
			
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		x= (A.size()%2 ? A[A.size()/2] : A[(A.size()-1)/2]);
		y= (B.size()%2 ? B[B.size()/2] : B[(B.size()-1)/2]);

		printf("(Street: %d, Avenue: %d)\n", x, y);

	}

	return 0;
}
