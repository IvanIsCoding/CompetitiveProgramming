# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2152
#!/usr/bin/env python
# -*- coding : utf-8 -*-
dicio = {x: "0%d" % (x) for x in range(0, 10)}
for x in range(10, 61):
    dicio[x] = str(x)
casos = int(input())
for caso in range(casos):
    a, b, c = [int(i) for i in input().split()]
    a = dicio[a]
    b = dicio[b]
    c = {1: "- A porta abriu!", 0: "- A porta fechou!"}[c]
    print("%s:%s %s" % (a, b, c))
