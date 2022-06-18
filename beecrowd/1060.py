# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1060
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
count = 0
for i in range(6):
    entrada = float(input())
    count += entrada > 0
print("%d valores positivos" % count)
