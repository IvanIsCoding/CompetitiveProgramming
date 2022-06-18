# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1449
#!/usr/bin/env python
# -*- coding : utf-8 -*-
ordem = int(input())
exibir = False
for caso_da_vez in range(ordem):
    dicio = {}
    a, b = [int(i) for i in input().split()]
    for i in range(a):
        entrada1 = input()
        entrada2 = input()
        dicio[entrada1] = entrada2
    for i in range(b):
        print(" ".join([dicio.get(j, j) for j in input().split()]))
    print("")
