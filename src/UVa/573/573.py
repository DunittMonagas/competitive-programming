#!/usr/bin/env 

'''*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                       UVa 573 - The Snail                     *
*****************************************************************
*'''


def main():
	

	while True:

		h, u, d, f = input().split()
		# h, u, d, f = map(float, input().split())
		# Explicit conversion is more efficient
		h = float(h)
		u = float(u)
		d = float(d)
		f = float(f)

		if h == 0:
			break

		cur = 0
		cont = 0
		f = (f/100) * u

		while True:
			
			cont += 1
			cur += u

			if cur > h:
				print("success on day", cont)
				break

			cur -= d
			if cur < 0:
				print("failure on day", cont)
				break

			u -= f
			if u < 0:
				u = 0

if __name__ == "__main__":
	main()
