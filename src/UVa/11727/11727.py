
'''
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 11727 - Cost Cutting                   *
*****************************************************************
'''


def main():
	
	t = int(input())

	for i in range(t):

		a, b, c = map(int, input().split())

		m = a
		if (a < b and a > c) or (a > b and a < c):
			m = a
		elif (b < a and b > c) or (b > a and b < c):
			m = b
		elif (c < b and c > a) or (c < a and c > b):
			m = c

		print("Case %d: %d" % (i+1, m))


if __name__ == "__main__":
	main()
