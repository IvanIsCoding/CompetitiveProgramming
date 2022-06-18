# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1799
#!/usr/bin/env python
# encoding : utf-8
from heapq import heappush, heappop


def dijkstra(graph, start):
    a = {x: None for x in list(graph.keys())}
    queue = [(0, start)]
    while queue:
        distance, v = heappop(queue)
        if a[v] is None:
            a[v] = distance
            for w in graph[v]:
                if a[w] is None:
                    heappush(queue, (distance + 1, w))
    return a


a, b = [int(i) for i in input().split(" ")]
grafo = {}
for i in range(b):
    c, d = input().split(" ")
    grafo[c] = grafo.get(c, []) + [d]
    grafo[d] = grafo.get(d, []) + [c]
print(dijkstra(grafo, "Entrada")["*"] + dijkstra(grafo, "*")["Saida"])
