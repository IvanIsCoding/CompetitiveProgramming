# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2060
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
array = [int(i) for i in input().split(" ")]
for j in [2, 3, 4, 5]:
    print("%d Multiplo(s) de %d" % (len([i for i in array if i % j == 0]), j))
