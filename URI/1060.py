# -*- coding: utf-8 -*-

'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''
count = 0
for i in xrange(6):
    entrada = float(raw_input())
    count += entrada > 0
print "%d valores positivos" % count
