# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2782
# -*- coding : utf-8 -*-

N = int(eval(input()))
vetor = [int(i) for i in input().split()]

intervalos = set()

for i in range(N):
    if i >= 1:
        ini = i
        fim = i
        diferenca = vetor[i] - vetor[i - 1]
        while ini >= 1 and vetor[ini] - vetor[ini - 1] == diferenca:
            ini -= 1
        while fim + 1 < N and vetor[fim + 1] - vetor[fim] == diferenca:
            fim += 1
        intervalos.add((ini, fim))
    if i + 1 < N:
        ini = i
        fim = i
        diferenca = vetor[i + 1] - vetor[i]
        while ini >= 1 and vetor[ini] - vetor[ini - 1] == diferenca:
            ini -= 1
        while fim + 1 < N and vetor[fim + 1] - vetor[fim] == diferenca:
            fim += 1
        intervalos.add((ini, fim))

print((max(len(intervalos), 1)))
