#!/usr/bin/env 

'''*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 10420 - List of Conquests                 *
*****************************************************************
*'''

def main():

	l = dict()

	n = int(input())
	for i in range(n):

		c, _ = input().split(maxsplit=1)

		l[c] = l.get(c, 0) + 1

	for k in sorted(l.keys()):
		print(k, l[k])


if __name__ == "__main__":
	main()
