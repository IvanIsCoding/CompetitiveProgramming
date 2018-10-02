# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2147
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
casos = int(raw_input())
for caso_da_vez in xrange(casos):
	print "%.2f" % (float(len(raw_input()))/100.0)
