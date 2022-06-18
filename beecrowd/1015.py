# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1015
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
a, b = [float(k) for k in input().split(" ")]
c, d = [float(k) for k in input().split(" ")]
print("%.4f" % (((a - c) ** 2 + (b - d) ** 2) ** 0.5))
