# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1728
#!/usr/bin/env python2.7
# *- coding : utf-8 -*-
while True:
	entrada = raw_input()
	if entrada == "0+0=0":
		print True
		break
	numeros = [int(i) for i in entrada[::-1].replace("=","+").split("+")]
	print numeros[0] == numeros[2] + numeros[1]
