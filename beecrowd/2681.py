# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2681
#!/usr/bin/env python
# -*- coding : utf-8 -*-
a = int(input())
resp = pow(2, a, 60 * 60 * 24) - 1
resp %= 60 * 60 * 24
a = resp / (60 * 60)
resp %= 60 * 60
b = resp / 60
resp %= 60
l1 = str(a)
if len(l1) == 1:
    l1 = "0" + l1
l2 = str(b)
if len(l2) == 1:
    l2 = "0" + l2
l3 = str(resp)
if len(l3) == 1:
    l3 = "0" + l3
print("%s:%s:%s" % (l1, l2, l3))
