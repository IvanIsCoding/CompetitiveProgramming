# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2152
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
dicio = {x: "0%d" % (x) for x in xrange(0,10)}
for x in xrange(10,61):
	dicio[x] = str(x)
casos = int(raw_input())
for caso in xrange(casos):
	a,b,c = [int(i) for i in raw_input().split()]
	a = dicio[a]
	b = dicio[b]
	c = {1:"- A porta abriu!",0:"- A porta fechou!"}[c]
	print "%s:%s %s" % (a,b,c)
