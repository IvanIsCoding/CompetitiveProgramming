# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1073
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
ordem = int(input())
for i in range(2, ordem + 1, 2):
    print("%d^2 = %d" % (i, i**2))
