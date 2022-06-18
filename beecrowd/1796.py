# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1796
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
ordem = int(input())
opinioes = [int(i) for i in input().split(" ")]
sim = opinioes.count(0)
nao = opinioes.count(1)
if nao >= sim:
    print("N")
else:
    print("Y")
