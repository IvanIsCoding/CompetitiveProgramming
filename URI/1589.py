# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1589
#!/usr/bin/env python2.7
# encoding : utf-8
ordem = int(raw_input())
for i in xrange(ordem):
	print sum([int(i) for i in raw_input().split(" ")])
