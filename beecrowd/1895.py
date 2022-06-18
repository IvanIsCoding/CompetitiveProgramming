# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1895
#!/usr/bin/env python
# encoding : utf-8
n, to, l = [int(i) for i in input().split(" ")]
counta = 0
countb = 0
for i in range(n - 1):
    e = int(input())
    if abs(e - to) <= l:
        if i % 2 == 0:
            counta += abs(e - to)
        else:
            countb += abs(e - to)
        to = e
print("%d %d" % (counta, countb))
