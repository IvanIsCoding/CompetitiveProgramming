# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1307
#!/usr/bin/env python
# encoding : utf-8
def gcd(a, b):
    x, y = sorted([a, b])
    if y % x == 0:
        return x
    else:
        return gcd(x, y % x)


ordem = int(input())
for i in range(1, ordem + 1):
    e1 = int(input(), 2)
    e2 = int(input(), 2)
    if gcd(e1, e2) == 1:
        print("Pair #%d: Love is not all you need!" % (i))
    else:
        print("Pair #%d: All you need is love!" % (i))
