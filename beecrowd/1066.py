# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1066
# -*- coding: utf-8 -*-
array = []
for i in range(5):
    array.append(int(input()))
for a, b in [
    ("valor(es) par(es)", lambda x: x % 2 == 0),
    ("valor(es) impar(es)", lambda x: x % 2 == 1),
    ("valor(es) positivo(s)", lambda x: x > 0),
    ("valor(es) negativo(s)", lambda x: x < 0),
]:
    print("%d %s" % (len([l for l in array if b(l)]), a))
