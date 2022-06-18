# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1261
#!/usr/bin/env python
# -*- coding : utf-8 -*-
a, b = [int(i) for i in input().split()]
dicio = {}
for caso_da_vez in range(a):
    c, d = input().split()
    dicio[c] = int(d)
for caso_da_vez in range(b):
    resposta = 0
    vetor = []
    while True:
        texto = input()
        if texto == ".":
            break
        else:
            for palavra in texto.split():
                resposta += dicio.get(palavra, 0)
    print(resposta)
