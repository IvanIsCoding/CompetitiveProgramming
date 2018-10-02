# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2482
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
linguas = int(raw_input())
dicio = {}
for i in xrange(linguas):
	lingua  = raw_input()
	mensagem = raw_input()
	dicio[lingua] = mensagem
nomes = int(raw_input())
for i in xrange(nomes):
	nome = raw_input()
	lingua = raw_input()
	print nome
	print dicio[lingua]
	print ""
