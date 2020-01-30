#!/usr/bin/python
a= int(raw_input())
for i in range(a):
	aux= raw_input()
	aux= aux.split(" ")
	b= int(aux[0])
	c= int(aux[1])
	print pow(b,c,10)