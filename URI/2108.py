# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2108
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
maior = 0
palavra = ""
while True:
	entrada = raw_input().split()
	resposta = []
	if entrada == ["0"]:
		break
	for i in entrada:
		tamanho = len(i)
		if tamanho >= maior:
			maior = tamanho
			palavra = i
		resposta.append(str(tamanho))
	print "-".join(resposta)
print "\nThe biggest word: %s" % palavra
