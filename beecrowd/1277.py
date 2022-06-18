# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1277
#!/usr/bin/env python
# -*- coding : utf-8 -*-
casos = int(input())
for caso_da_vez in range(casos):
    numero = int(input())
    alunos = input().split()
    presenca = [k.replace("M", "") for k in input().split()]
    faltas = []
    for aluno, falta in zip(alunos, presenca):
        if falta.count("P") / float(len(falta)) < 0.75:
            faltas.append(aluno)
    print(" ".join(faltas))
