# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1173
#!/usr/bin/env python
# encoding : utf-8
entrada = int(input())
array = [entrada * (2**i) for i in range(10)]
for a, b in enumerate(array):
    print("N[%d] = %d" % (a, b))
