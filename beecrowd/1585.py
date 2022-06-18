# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1585
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
ordem = int(input())
for i in range(ordem):
    a, b = [int(i) for i in input().split(" ")]
    print("%s cm2" % str(a * b / 2))
