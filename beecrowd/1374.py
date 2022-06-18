# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1374
#!/usr/bin/env python
# -*- coding : utf-8 -*-
import datetime

while True:
    n = int(input())
    if n == 0:
        break
    resp = 0
    cont = 0
    lista1 = []
    lista2 = []
    for i in range(n):
        a, b, c, d = [int(i) for i in input().split()]
        lista1.append(datetime.datetime(c, b, a))
        lista2.append(d)
    for i in range(1, n):
        if lista1[i] - datetime.timedelta(days=1) == lista1[i - 1]:
            cont += 1
            resp += lista2[i] - lista2[i - 1]
    print("%d %d" % (cont, resp))
