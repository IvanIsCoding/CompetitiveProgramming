# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1547
# encoding: utf-8
ordem = int(input())
casos = []
alunos = []
for i in range(ordem):
    casos.append([int(i) for i in input().split(" ")])
    alunos.append(input())
for a, b in enumerate(casos):
    qt, s = b
    array = [abs(int(k) - s) for k in alunos[a].split(" ")]
    print(1 + array.index(min(array)))
