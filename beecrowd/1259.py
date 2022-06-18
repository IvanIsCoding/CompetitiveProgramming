# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1259
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
pares = []
impares = []
for i in range(ordem):
    j = int(input())
    if j % 2 == 0:
        pares.append(j)
    else:
        impares.append(j)
for i in sorted(pares):
    print(i)
for i in sorted(impares)[::-1]:
    print(i)
