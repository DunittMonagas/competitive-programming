
'''
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                 UVa 11172 - Relational Operator               *
*****************************************************************
'''

def main():
	
	t = int(input())

	for i in range(t):
		a, b = map(int, input().split())

		if a < b:
			print("<")

		elif a > b:
			print(">")

		else:
			print("=")


if __name__ == "__main__":
	main()

