# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1589
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(ordem):
    print(sum([int(i) for i in input().split(" ")]))
