# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1260
#!/usr/bin/env python
# -*- coding : utf-8 -*-
from collections import Counter

ordem = int(input())
input()
for caso_da_vez in range(ordem - 1):
    contador = Counter()
    count = 0
    while True:
        entrada = input()
        if entrada.split():
            contador[entrada] += 1.0
            count += 1.0
        else:
            break
    for a, b in sorted(contador.most_common()):
        print("%s %.4f" % (a, 100.0 * (b / count)))
    print("")
contador = Counter()
count = 0
while True:
    try:
        entrada = input()
        contador[entrada] += 1.0
        count += 1.0
    except EOFError:
        break
for a, b in sorted(contador.most_common()):
    print("%s %.4f" % (a, 100.0 * (b / count)))
