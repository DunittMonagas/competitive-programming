#!/usr/bin/env 

'''*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 10812 - Beat the Spread!                 *
*****************************************************************
*''' 

def main():
	
	n = int(input())

	for i in range(n):

		s, d = input().split()
		s, d = int(s), int(d)

		x = (d + s)//2
		y =  s - x

		if (x >= 0) and (y >= 0) and (x + y == s) and (abs(x - y) == d):
			print(x, y)
		else:
			print("impossible")

if __name__ == "__main__":
	main()
