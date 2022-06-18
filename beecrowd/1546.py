# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1546
# -*- coding: utf-8 -*-
ordem = int(input())
casos = []
for i in range(ordem):
    subordem = int(input())
    problemas = []
    for i in range(subordem):
        problemas.append(int(input()))
    casos.append(problemas)
for teste in casos:
    for numero in teste:
        print({1: "Rolien", 2: "Naej", 3: "Elehcim", 4: "Odranoel"}[numero])
