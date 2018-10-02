# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2158
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
molecula = 0
while True:
	try:
		a,b = [int(i) for i in raw_input().split()]
	except EOFError:
		break
	molecula += 1
	print "Molecula #%d.:." % (molecula)
	ligacoes = (a*5 + b*6)/2
	atomos = 2 - a - b + ligacoes
	print "Possui %d atomos e %d ligacoes" % (atomos,ligacoes)
	print ""
