# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1580
#!/usr/bin/env python
# -*- coding : utf-8 -*-
from math import factorial

alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
modulo = 10**9 + 7
precalculo = {}
for i in range(1001):
    precalculo[i] = factorial(i)
while True:
    try:
        entrada = input()
    except EOFError:
        break
    dicio = {i: 0 for i in alfabeto}
    for i in entrada:
        dicio[i] += 1
    grandao = precalculo[len(entrada)]
    for a, b in dicio.items():
        grandao /= precalculo[b]
    print(grandao % modulo)
