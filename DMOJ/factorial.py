# Ivan Carvalho
# Solution to https://dmoj.ca/problem/factorial
#!/usr/bin/env python
# -*- coding : utf-8 -*-
mod = 2**32
testes = int(input())
for vez in range(testes):
    fat = 1
    n = int(input())
    if n >= 50:
        print(0)
        continue
    for i in range(2, n + 1):
        fat *= i
        fat %= mod
    print(fat)
