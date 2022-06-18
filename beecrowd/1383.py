# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1383
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
padrao = list(range(1, 10))
resposta = []
for j in range(ordem):
    aquilo = "Instancia %d" % (j + 1)
    resposta.append(aquilo)
    array = []
    teste = 0
    for i in range(9):
        array.append([int(k) for k in input().split(" ")])
    for i in array:
        if sorted(i) != padrao:
            teste = 1
    for i in zip(*array):
        if sorted(list(i)) != padrao:
            teste = 1
    for i in [0, 3, 6]:
        for k in [0, 3, 6]:
            if (
                sorted(
                    [
                        array[i][k],
                        array[i][k + 1],
                        array[i][k + 2],
                        array[i + 1][k],
                        array[i + 1][k + 1],
                        array[i + 1][k + 2],
                        array[i + 2][k],
                        array[i + 2][k + 1],
                        array[i + 2][k + 2],
                    ]
                )
                != padrao
            ):
                teste = 1
    if teste == 1:
        resposta.extend(["NAO", ""])
    else:
        resposta.extend(["SIM", ""])
for j in resposta:
    print(j)
