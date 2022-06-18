# Ivan Carvalho
# Solution to https://dmoj.ca/problem/bf1hard
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
from sys import stdin

raw_input = stdin.readline
a = int(input())
v = []
for i in range(a):
    j = int(input())
    v.append(j)
v.sort()
for i in v:
    print(i)
