
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*              Live Archive 6133 - Cellphone Typing             *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

#define MAXPAL 100
#define MAX 100010

int T[MAX];
char DIC[MAX][MAXPAL];

struct Nodo{

    int C;
    bool P;
    Nodo *H[30];

    Nodo(){

        C= 0;
        P= false;
        for (int i = 0; i<30; ++i)
            H[i]= NULL;

    }

};

Nodo *Raiz;

void Agregar(const char *str, int n){

    Nodo *Actual= Raiz;

    for(int i= 0; i<n; ++i){

        if(Actual->H[str[i]-'a'] == NULL){
            Actual->H[str[i]-'a']= new Nodo();
            Actual->C++;
        }

        Actual= Actual->H[str[i]-'a'];
    
    }

    Actual->P= true;

}

int F(int i){
    
    Nodo *Actual= Raiz;
    int n= T[i], cont= 1;
    const char *str= DIC[i];

    Actual= Actual->H[str[0]-'a'];

    for(int l= 1; l<n; ++l){

        if((Actual->C > 1) || (Actual->P))
            ++cont;

        Actual= Actual->H[str[l]-'a'];

    }

    return cont;
}


int main(){

    int n;
    float pro, aux;
    
    while(scanf("%d", &n) != EOF){

        pro= 0.0;
        Raiz= new Nodo();

        for (int i= 0; i<n; ++i){

            scanf("%s", DIC[i]);

            T[i]= strlen(DIC[i]);
            Agregar(DIC[i], T[i]);

        }

        for(int i= 0; i<n; ++i)
            pro+= (float) F(i);

        printf("%.2f\n", pro/(float)n);

    }

    return 0;
}