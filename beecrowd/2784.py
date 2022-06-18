# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2784
# -*- coding : utf-8 -*-

from heapq import heappush, heappop

N, M = [int(i) for i in input().split()]

grafo = {}
distancias = {}
processado = set()

for i in range(1, N + 1):
    grafo[i] = []

for i in range(M):
    u, v, w = [int(j) for j in input().split()]
    grafo[u].append((v, w))
    grafo[v].append((u, w))

S = int(eval(input()))

pq = []
heappush(pq, (0, S))

while pq:
    dist, v = heappop(pq)
    if v in processado:
        continue
    processado.add(v)
    distancias[v] = dist
    for u, w in grafo[v]:
        if u in processado:
            continue
        heappush(pq, (dist + w, u))

lista_ping = sorted(list(distancias.values()))
print((lista_ping[-1] - lista_ping[1]))
