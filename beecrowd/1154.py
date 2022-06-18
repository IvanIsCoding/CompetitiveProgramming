# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1154
#!/usr/bin/env python
# encoding : utf-8
array = []
while True:
    entrada = int(input())
    if entrada < 0:
        break
    else:
        array.append(entrada)
print("%.2f" % (sum(array) / float(len(array))))
