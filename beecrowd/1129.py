# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1129
#!/usr/bin/env python
# -*- coding : utf-8
while True:
    a = int(input())
    if a == 0:
        break
    for i in range(a):
        entrada = [int(i) <= 127 for i in input().split()]
        if entrada.count(True) == 1:
            print("ABCDE"[entrada.index(True)])
        else:
            print("*")
