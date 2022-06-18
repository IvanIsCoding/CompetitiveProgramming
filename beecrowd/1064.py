# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1064
# -*- coding: utf-8 -*-
array = []
for i in range(6):
    entrada = float(input())
    if entrada > 0:
        array.append(entrada)
print("%d valores positivos" % len(array))
print("%.1f" % (sum(array) / float(len(array))))
