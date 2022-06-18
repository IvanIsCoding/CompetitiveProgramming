# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1869
#!/usr/bin/env python
# -*- coding : utf -8 -*-
alfabeto = "0123456789ABCDEFGHIJKLMNOPQRSTUV"
dicio = {}
for i in range(len(alfabeto)):
    dicio[i] = alfabeto[i]
while True:
    n = int(input())
    if n == 0:
        print("0")
        break
    invertido = []
    while n > 0:
        invertido.append(dicio[n % 32])
        n /= 32
    print("".join(invertido)[::-1])
