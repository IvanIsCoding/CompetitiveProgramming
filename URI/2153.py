# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2153
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
while True:
	try:
		entrada = raw_input()[::-1]
	except EOFError:
		break
	tamanho = len(entrada)
	i=1
	while entrada.count(entrada[:i])>1 and i <= tamanho:
		i += 1
	trecho = entrada[:i-1]
	entrada = entrada.replace(trecho,"",entrada.count(trecho)-1)
	print entrada[::-1]
