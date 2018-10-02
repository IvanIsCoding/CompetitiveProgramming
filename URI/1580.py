# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1580
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
from math import factorial
alfabeto = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
modulo = 10**9 + 7
precalculo = {}
for i in xrange(1001):
	precalculo[i] = factorial(i)
while True:
	try:
		entrada = raw_input()
	except EOFError:
		break
	dicio = {i : 0 for i in alfabeto}
	for i in entrada:
		dicio[i] += 1
	grandao = precalculo[len(entrada)]
	for a,b in dicio.iteritems():
		grandao /= precalculo[b]
	print grandao % modulo
