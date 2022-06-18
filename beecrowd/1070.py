# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1070
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
entrada = int(input())
if entrada % 2 == 0:
    entrada += 1
for i in range(6):
    print(entrada + i * 2)
