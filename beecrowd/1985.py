# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1985
#!/usr/bin/env python
# -*- coding : utf-8 -*-
dicio = {1001: 1.5, 1002: 2.5, 1003: 3.5, 1004: 4.5, 1005: 5.5}
casos = int(input())
resposta = 0
for i in range(casos):
    a, b = [int(j) for j in input().split(" ")]
    resposta += dicio.get(a, 0) * b
print("%.2f" % resposta)
