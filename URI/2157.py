# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2157
#!/usr/bbin/env python2.7
# -*- coding : utf-8 -*-
tc = int(raw_input())
for algo in xrange(tc):
	a,b = [int(i) for i in raw_input().split()]
	lista = []
	reverso = []
	for i in xrange(a,b+1):
		lista.append(str(i))
		reverso.append(str(i)[::-1])
	print "".join(lista + reverso[::-1])
