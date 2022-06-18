# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1555
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
numeros = []
for i in range(ordem):
    numeros.append([int(i) for i in input().split(" ")])


def maior(x, y):
    rafael = ((3 * x) ** 2) + (y**2)
    beto = 2 * (x**2) + (5 * y) ** 2
    carlos = -100 * x + y**3
    if rafael > carlos and rafael > beto:
        return "Rafael ganhou"
    elif beto > carlos and beto > rafael:
        return "Beto ganhou"
    else:
        return "Carlos ganhou"


for p, q in numeros:
    print(maior(p, q))
