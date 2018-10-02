# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1581
#!/usr/bin/env python2.7
# encoding : utf-8
ordem = int(raw_input())
linguas = []
for i in xrange(ordem):
	subordem = int(raw_input())
	sublinguas = []
	for j in xrange(subordem):
		sublinguas.append(raw_input())
	linguas.append(sublinguas)
for array in linguas:
	lingua = array[0]
	if all([k==lingua for k in array]):
		print lingua
	else:
		print "ingles"
