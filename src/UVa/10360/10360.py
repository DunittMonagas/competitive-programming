#!/usr/bin/env

"""*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                    UVa 10360 - Rat Attack                     *
*****************************************************************
*""" 


def main():

	from sys import stdin, stdout
	lines = [line for line in stdin.readlines() if line.strip()]

	cont = 1
	str_output = ""
	s = int(lines[0])

	for _ in range(s):

		d = int(lines[cont])
		cont += 1

		n = int(lines[cont])
		cont += 1

		smax = 0
		rmin, cmin = 1025, 1025
		T = [[0] * 1025 for _ in range(1025)]

		for _ in range(n):
			x, y, i = [int(k) for k in lines[cont].split()]


			r = x - d
			while abs(r - x) <= d:

				c = y - d
				while abs(c - y) <= d:

					if not ((r >= 0 and r < 1025) and (c >= 0 and c < 1025)):
						c += 1
						continue

					T[r][c] += i

					if T[r][c] > smax:
						smax = T[r][c]
						rmin, cmin = r, c

					elif (T[r][c] == smax) and ((r < rmin) or (r == rmin and c < cmin)):
						rmin, cmin = r, c

					c += 1
				r += 1

			cont += 1

		str_output += " ".join([str(rmin), str(cmin), str(smax) + "\n"])

	stdout.write(str_output)


if __name__ == "__main__":
	main()
