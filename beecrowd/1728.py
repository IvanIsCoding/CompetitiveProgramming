# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1728
#!/usr/bin/env python
# *- coding : utf-8 -*-
while True:
    entrada = input()
    if entrada == "0+0=0":
        print(True)
        break
    numeros = [int(i) for i in entrada[::-1].replace("=", "+").split("+")]
    print(numeros[0] == numeros[2] + numeros[1])
