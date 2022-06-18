# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1158
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(ordem):
    a, b = [int(i) for i in input().split(" ") if i != ""]
    if a % 2 == 0:
        a += 1
    soma = 0
    count = 0
    while count < b:
        soma += a
        count += 1
        a += 2
    print(soma)
