# Ivan Carvalho
# Solution to https://dmoj.ca/problem/ccc96s4
#!/usr/bin/env python
# -*- coding : utf-8 -*-
def to_roman(entrada):
    array = []
    for a, b in [
        ("M", 1000),
        ("CM", 900),
        ("D", 500),
        ("CD", 400),
        ("C", 100),
        ("XC", 90),
        ("L", 50),
        ("XL", 40),
        ("X", 10),
        ("IX", 9),
        ("V", 5),
        ("IV", 4),
        ("I", 1),
    ]:
        total = int(entrada / b)
        for k in range(total):
            array.append(a)
        entrada %= b
    return "".join(array)


mapa = {}
for i in range(1, 1001):
    mapa[to_roman(i)] = i
casos = int(input())
for vez in range(casos):
    a, b = input().replace("+", " ").replace("=", "").split()
    xa = 1001
    if a in mapa:
        xa = mapa[a]
    xb = 1001
    if b in mapa:
        xb = mapa[b]
    resultado = xa + xb
    if resultado <= 1000:
        print("%s+%s=%s" % (a, b, to_roman(resultado)))
    else:
        print("%s+%s=CONCORDIA CUM VERITATE" % (a, b))
