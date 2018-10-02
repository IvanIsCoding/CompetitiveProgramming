# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1620
# -*- coding: utf-8 -*-

'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''
while True:
    a = float(raw_input())
    if a == 0:
        break
    else:
        print "%.6f" % ((a-3)/a)
