# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1082
#!/usr/bin/env python
# -*- coding : utf-8 -*-
casos = int(input())
alfabeto = "abcdefghijklmnopqrstuvwxyz"
for caso_da_vez in range(casos):
    vertices, arestas = [int(i) for i in input().split()]
    letras = alfabeto[:vertices]
    grafo = {x: [] for x in letras}
    jaesteve = {x: 1 for x in letras}
    for aresta_da_vez in range(arestas):
        componente1, componente2 = input().split()
        grafo[componente1].append(componente2)
        grafo[componente2].append(componente1)
    print("Case #%d:" % (caso_da_vez + 1))
    resposta = 0
    for letra in letras:
        if jaesteve[letra]:
            resposta += 1
            caminho = []
            pilha = [letra]
            while pilha:
                v = pilha.pop()
                if jaesteve[v]:
                    caminho.append(v + ",")
                    pilha.extend(grafo[v])
                    jaesteve[v] = 0
            print("".join(sorted(caminho)))
    print("%d connected components\n" % resposta)
