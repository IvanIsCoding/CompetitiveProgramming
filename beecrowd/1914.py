# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1914
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(ordem):
    a, b, c, d = input().split(" ")
    e, f = [int(k) for k in input().split(" ")]
    if b == "PAR":
        if (e + f) % 2 == 0:
            print(a)
        else:
            print(c)
    else:
        if (e + f) % 2 == 0:
            print(c)
        else:
            print(a)
