# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1071
#!/usr/bin/env python
# encoding : utf-8
a = int(input())
b = int(input())
x, y = sorted([a, b])
if x % 2 == 1:
    x += 2
else:
    x += 1
print(sum(range(x, y, 2)))
