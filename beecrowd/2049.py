# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2049
#!/usr/bin/env/python
# -*- coding : utf-8 -*-
instancia = 1
while True:
    entrada = input()
    if entrada == "0":
        break
    if instancia != 1:
        print("")
    checar = input()
    print("Instancia %d" % instancia)
    instancia += 1
    if entrada in checar:
        print("verdadeira")
    else:
        print("falsa")
