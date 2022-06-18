# Ivan Carvalho
# Solution to https://dmoj.ca/problem/gfssoc3s1
#!/usr/bin/env python
# -*- coding : utf-8 -*-
n = int(input())
resp = ""
pot = 0
while 2**pot <= n:
    resp = resp + "1"
    pot += 1
print(resp)
