# Ivan Carvalho
# Solution to https://dmoj.ca/problem/bf1
#!/usr/bin/env python
# -*- coding : utf-8 -*-
a = int(input())
v = []
for i in range(a):
    j = int(input())
    v.append(j)
v.sort()
for i in v:
    print(i)
