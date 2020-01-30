
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                       UVa 573 - The Snail                     *
*****************************************************************
*/

#include <cstdio>

int main(){

	float a, ds, dc, f, c;
	int d;

	scanf("%f %f %f %f",&a,&ds,&dc,&f);

	while(a!=0){

		d=0;
		c= 0;
		f=(f/100)*ds;
		
		do{

			d++;
			c+= ds;
			if(c>a)break;
			c-= dc;
			if(c<0) break;
			ds+=-f;
			if(ds<0) ds=0;

		}while(c>=0 && c<=a);

		if(c>=a ? printf("success on day %d\n",d):printf("failure on day %d\n",d));
		scanf("%f %f %f %f",&a,&ds,&dc,&f);
	}
	
	return 0;
}
