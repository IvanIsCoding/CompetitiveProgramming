# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1805
#!/usr/bin/env python
# encoding : utf-8
a, b = [int(i) for i in input().split(" ")]
soma = lambda x: ((x) * (x + 1)) / 2
print(soma(b) - soma(a - 1))
