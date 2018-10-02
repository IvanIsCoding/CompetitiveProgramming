# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1555
#!/usr/bin/env python2.7
# encoding : utf-8
ordem = int(raw_input())
numeros = []
for i in xrange(ordem):
	numeros.append([int(i) for i in raw_input().split(" ")])
def maior(x,y):
	rafael = ((3*x)**2)+ (y**2)
	beto = 2*(x**2)+ (5*y)**2
	carlos = -100*x + y**3
	if rafael > carlos and rafael > beto:
		return "Rafael ganhou"
	elif beto > carlos and beto > rafael:
		return "Beto ganhou"
	else:
		return "Carlos ganhou"
for p,q in numeros:
	print maior(p,q)
