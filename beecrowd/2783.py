# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2783
# -*- coding : utf-8 -*-

N, C, M = [int(i) for i in input().split()]
cjt1 = set([int(i) for i in input().split()])
cjt2 = set([int(i) for i in input().split()])

print((len(cjt1 - cjt2)))
