# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1963
#!/usr/bin/env python
# encoding : utf-8
a, b = [float(i) for i in input().split(" ")]
print("%.2f%%" % (100 * ((b / a) - 1.00)))
