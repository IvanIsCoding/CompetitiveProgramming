# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2786
# -*- coding : utf-8 -*-

L = int(eval(input()))
C = int(eval(input()))

print((L * C + (L - 1) * (C - 1)))
print(((L + C - 2) * 2))
