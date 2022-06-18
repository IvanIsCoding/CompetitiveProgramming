# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2134
#!/usr/bin/env python
# -*- coding : utf-8 -*-
count = 1
while True:
    try:
        ordem = int(input())
    except EOFError:
        break
    lista = []
    for i in range(ordem):
        a, b = input().split()
        lista.append((-int(b), a))
    lista.sort()
    print("Instancia %d" % count)
    count += 1
    print(lista[-1][1])
    print("")
