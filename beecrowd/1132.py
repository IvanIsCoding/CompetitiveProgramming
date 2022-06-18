# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1132
#!/usr/bin/env python
# encoding : utf-8
entrada1 = int(input())
entrada2 = int(input())
a, b = sorted([entrada1, entrada2])


def soma(x):
    return ((x) * (x + 1)) / 2


def multiplo(y):
    if y % 13 == 0:
        return y
    else:
        return y - (y % 13) + 13


print(soma(b) - (sum([i for i in range(multiplo(a), b + 1, 13)]) + soma(a - 1)))
