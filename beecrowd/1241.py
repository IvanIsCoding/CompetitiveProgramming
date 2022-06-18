# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1241
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(ordem):
    a, b = input().split(" ")
    a, b = a[::-1], b[::-1]
    if len(a) >= len(b):
        if all([a[j] == b[j] for j in range(len(b))]):
            print("encaixa")
        else:
            print("nao encaixa")
    else:
        print("nao encaixa")
