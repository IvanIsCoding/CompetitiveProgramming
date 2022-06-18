# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1144
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(1, ordem + 1):
    print("%d %d %d" % (i, i**2, i**3))
    print("%d %d %d" % (i, i**2 + 1, i**3 + 1))
