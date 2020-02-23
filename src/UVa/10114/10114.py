
'''
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 10114 - Loansome Car Buyer               *
*****************************************************************
'''

def main():
	
	while True:

		m, dp, l, dr = input().split()
		
		m = int(m)
		dp = float(dp)
		l = float(l)
		dr = int(dr)

		if m <= 0:
			break

		ind, per = [], []
		for i in range(dr):
			n, d = input().split()

			ind.append(int(n))
			per.append(float(d))

		prev = m
		sd = [None] * (m + 1)

		for i in range(len(ind), 0, -1):
			for k in range(prev, ind[i - 1] - i, -1):
				sd[k] = per[i - 1]

			prev = ind[i - 1] - 1

		cont = 0
		p = l/m
		w = (l + dp) - (l + dp)*sd[cont]

		while(l >= w):
			cont += 1

			l -= p
			w -= w*sd[cont]

		if cont == 1:
			print("%d month" % (cont))
		else:
			print("%d months" % (cont))


if __name__ == "__main__":
	main()

