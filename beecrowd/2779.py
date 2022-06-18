# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2779
# -*- coding : utf-8 -*-

N = int(eval(input()))
M = int(eval(input()))
cjt = set()

for i in range(M):
    x = int(eval(input()))
    cjt.add(x)

print((N - len(cjt)))
