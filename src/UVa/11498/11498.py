
'''
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*               UVa 11498 - Division of Nlogonia                *
*****************************************************************
'''

def main():
	
	while True:

		k = int(input())
		if k == 0:
			break

		n, m = map(int, input().split())

		for i in range(k):
			x, y = map(int, input().split())

			if (x == n) or (y == m):
				print("divisa")

			elif x > n:
				if y > m:
					print("NE")
				else:
					print("SE")

			else:
				if y > m:
					print("NO")
				else:
					print("SO")


if __name__ == "__main__":
	main()
