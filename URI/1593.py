# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1593
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
casos = int(raw_input())
for i in xrange(casos):
	print str(bin(int(raw_input()))).count("1")
