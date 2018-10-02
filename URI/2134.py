# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2134
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
count = 1
while True:
	try:
		ordem = int(raw_input())
	except EOFError:
		break
	lista = []
	for i in xrange(ordem):
		a,b = raw_input().split()
		lista.append((-int(b),a))
	lista.sort()
	print "Instancia %d" % count
	count += 1
	print lista[-1][1]
	print ""
