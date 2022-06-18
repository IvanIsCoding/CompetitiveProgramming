# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1452
#!/usr/bin/env python
# -*- coding : utf-8 -*-
while True:
    n, m = [int(i) for i in input().split()]
    if n == 0 and m == 0:
        break
    servidores = []
    usuarios = []
    conexoes = 0
    for i in range(n):
        servidores.append(set(input().split()[1:]))
    for i in range(m):
        usuarios.append(set(input().split()[1:]))
    for i in usuarios:
        for j in servidores:
            if j.intersection(i):
                conexoes += 1
    print(conexoes)
