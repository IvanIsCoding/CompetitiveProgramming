# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1794
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
n = int(input())
min1, max1 = [int(i) for i in input().split(" ")]
min2, max2 = [int(i) for i in input().split(" ")]
if n >= min1 and n >= min2 and n <= max1 and n <= max2:
    print("possivel")
else:
    print("impossivel")
