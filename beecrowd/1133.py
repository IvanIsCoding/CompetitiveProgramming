# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1133
#!/usr/bin/env python
# encoding : utf-8
a = int(input())
b = int(input())
x, y = sorted([a, b])
for i in [k for k in range(x + 1, y) if k % 5 == 2 or k % 5 == 3]:
    print(i)
