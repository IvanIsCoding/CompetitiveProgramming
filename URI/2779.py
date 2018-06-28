# -*- coding : utf-8 -*-

N = int(input())
M = int(input())
cjt = set()

for i in range(M):
	x = int(input())
	cjt.add(x)

print(N - len(cjt))