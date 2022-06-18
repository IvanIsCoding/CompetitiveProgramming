# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1249
#!/usr/bin/env python
# encoding : utf-8
dicio = {}
alfabeto = "abcdefghijklmnopqrstuvwxyz"
for a, b in enumerate([k for k in alfabeto]):
    dicio[b] = alfabeto[(a + 13) % 26]
    dicio[b.upper()] = dicio[b].upper()
while True:
    try:
        entrada = input()
        print("".join([dicio.get(j, j) for j in entrada]))
    except EOFError:
        break
