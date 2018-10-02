# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2779
# -*- coding : utf-8 -*-

N = int(input())
M = int(input())
cjt = set()

for i in range(M):
	x = int(input())
	cjt.add(x)

print(N - len(cjt))