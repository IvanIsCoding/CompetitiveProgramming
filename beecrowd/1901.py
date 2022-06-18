# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1901
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
ordem = int(input())
array = []
for i in range(ordem):
    array.append([int(k) for k in input().split(" ")])
pares = []
for j in range(ordem * 2):
    pares.append([int(l) - 1 for l in input().split(" ")])
encontrados = []
for c, d in pares:
    encontrados.append(array[c][d])
print(len(set(encontrados)))
