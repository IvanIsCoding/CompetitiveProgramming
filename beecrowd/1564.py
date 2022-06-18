# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1564
# -*- coding: utf-8 -*-

"""
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
"""
while True:
    try:
        e = int(input())
        if e == 0:
            print("vai ter copa!")
        else:
            print("vai ter duas!")
    except EOFError:
        break
