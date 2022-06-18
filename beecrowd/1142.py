# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1142
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
i = 1
count = 0
while count < ordem:
    print("%d %d %d PUM" % (i, i + 1, i + 2))
    i += 4
    count += 1
