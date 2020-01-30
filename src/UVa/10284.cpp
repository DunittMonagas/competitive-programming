
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*  	              UVa 10284 - Chessboard in FEN                 *
*****************************************************************
*/

#include <cstdio>
#include <cstring>

#define UNOCCUPIED 0
#define ATTACKED 1
#define KING 2
#define QUEEN 3
#define ROOK 4
#define BISHOP 5
#define KNIGHT 6
#define BPAWN 7
#define WPAWN 8
#define TODIGIT(c) (c - '0')
#define VALID(x, y) (((x >= 0) && (x < 8)) && ((y >= 0) && (y < 8)))

int T[8][8];
char str[100];

int P[]= {-1, 1};	//BLACK AND WHITE PAWN

int RX[]= {0, 1, 0, -1};	//ROOK(X)
int RY[]= {-1, 0, 1, 0};	//ROOK(Y)

int BX[]= {-1, 1, 1, -1};	//BISHOP(X)
int BY[]= {-1, -1, 1, 1};	//BISHOP(Y)

int KX[]= {0, 1, 1, 1, 0, -1, -1, -1};	//KING(X)
int KY[]= {-1, -1, 0, 1, 1, 1, 0, -1};	//KING(Y)

int NX[]= {-1, 1, 2, 2, 1, -1, -2, -2};	//KNIGHT(X)
int NY[]= {-2, -2, -1, 1, 2, 2, 1, -1};	//KNIGHT(Y)

int F(){

	int x = 0, y = 0;
	int sz = strlen(str);
	for(int i = 0; i< sz; ++i){

		if(str[i] == 'p')
			T[y][x]= BPAWN;
		else if(str[i] == 'P')
			T[y][x]= WPAWN;
		else if(str[i] == 'R' || str[i] == 'r')
			T[y][x]= ROOK;
		else if(str[i] == 'N' || str[i] == 'n')
			T[y][x]= KNIGHT;
		else if(str[i] == 'B' || str[i] == 'b')
			T[y][x]= BISHOP;
		else if(str[i] == 'Q' || str[i] == 'q')
			T[y][x]= QUEEN;
		else if(str[i] == 'K' || str[i] == 'k')
			T[y][x]= KING;
		else if(str[i] == '/'){
			++y;
			continue;
		}else{
			x= (x + TODIGIT(str[i]))%8;
			continue;
		}

		x = (x + 1)%8;

	}

	for(y= 0; y<8; ++y)
		for(x= 0; x<8; ++x){

			switch(T[y][x]){

				case BPAWN:
					for(int w=0; w<2; ++w)
						if(VALID(y + 1, x + P[w]) && T[y + 1][x + P[w]] == UNOCCUPIED)
							T[y + 1][x + P[w]]= ATTACKED;
					break;

				case WPAWN:
					for(int w=0; w<2; ++w)
						if(VALID(y - 1, x + P[w]) && T[y - 1][x + P[w]] == UNOCCUPIED)
							T[y - 1][x + P[w]]= ATTACKED;
					break;

				case ROOK:
					for(int w=0; w<4; ++w)
						for(int k = 1; k<8; ++k)
							if(VALID(y + k*RY[w], x + k*RX[w]))
								if(T[y + k*RY[w]][x + k*RX[w]] != UNOCCUPIED && T[y + k*RY[w]][x + k*RX[w]] != ATTACKED)
									break;
								else
									T[y + k*RY[w]][x + k*RX[w]]= ATTACKED;
					break;

				case KNIGHT:
					for(int k = 0; k<8; ++k)
						if(VALID(y + NY[k], x + NX[k]) && T[y + NY[k]][x + NX[k]] == UNOCCUPIED)
							T[y + NY[k]][x + NX[k]]= ATTACKED;
					break;

				case BISHOP:
					for(int w=0; w<4; ++w)
						for(int k = 1; k<8; ++k)
							if(VALID(y + k*BY[w], x + k*BX[w]))
								if(T[y + k*BY[w]][x + k*BX[w]] != UNOCCUPIED && T[y + k*BY[w]][x + k*BX[w]] != ATTACKED)
									break;
								else
									T[y + k*BY[w]][x + k*BX[w]]= ATTACKED;
					break;

				case QUEEN:
					for(int w=0; w<4; ++w)
						for(int k = 1; k<8; ++k)
							if(VALID(y + k*RY[w], x + k*RX[w]))
								if(T[y + k*RY[w]][x + k*RX[w]] != UNOCCUPIED && T[y + k*RY[w]][x + k*RX[w]] != ATTACKED)
									break;
								else
									T[y + k*RY[w]][x + k*RX[w]]= ATTACKED;

					for(int w=0; w<4; ++w)
						for(int k = 1; k<8; ++k)
							if(VALID(y + k*BY[w], x + k*BX[w]))
								if(T[y + k*BY[w]][x + k*BX[w]] != UNOCCUPIED && T[y + k*BY[w]][x + k*BX[w]] != ATTACKED)
									break;
								else
									T[y + k*BY[w]][x + k*BX[w]]= ATTACKED;
					break;

				case KING:
					for(int k = 0; k<8; ++k)
						if(VALID(y + KY[k], x + KX[k]) && T[y + KY[k]][x + KX[k]] == UNOCCUPIED)
							T[y + KY[k]][x + KX[k]]= ATTACKED;
					break;

			}

		}

	int rest = 0;
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			if(T[i][j] == UNOCCUPIED) ++rest;

	return rest;

}

int main(){

	while(scanf("%s", str) != EOF){

		printf("%d\n", F());
		memset(T, UNOCCUPIED, sizeof(T));

	}

	return 0;
}