# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1240
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(ordem):
    a, b = input().split(" ")
    ta, tb = [len(a), len(b)]
    if tb > ta:
        print("nao encaixa")
    else:
        if b in a[::-1][:tb][::-1]:
            print("encaixa")
        else:
            print("nao encaixa")
