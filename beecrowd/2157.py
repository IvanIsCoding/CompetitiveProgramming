# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2157
#!/usr/bbin/env python
# -*- coding : utf-8 -*-
tc = int(input())
for algo in range(tc):
    a, b = [int(i) for i in input().split()]
    lista = []
    reverso = []
    for i in range(a, b + 1):
        lista.append(str(i))
        reverso.append(str(i)[::-1])
    print("".join(lista + reverso[::-1]))
