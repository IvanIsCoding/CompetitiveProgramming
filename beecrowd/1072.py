# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1072
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
ordem = int(input())
dentro = 0
fora = 0
for j in range(ordem):
    i = int(input())
    if i >= 10 and i <= 20:
        dentro += 1
    else:
        fora += 1
print("%d in" % dentro)
print("%d out" % fora)
