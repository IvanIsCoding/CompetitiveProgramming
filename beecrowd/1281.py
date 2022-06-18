# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1281
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
ordem = int(input())
for i in range(ordem):
    dicio = {}
    quantidade1 = int(input())
    for j in range(quantidade1):
        a, b = input().split(" ")
        dicio[a] = float(b)
    quantidade2 = int(input())
    soma = 0
    for j in range(quantidade2):
        c, d = input().split(" ")
        soma += dicio[c] * int(d)
    print("R$ %.2f" % (soma))
