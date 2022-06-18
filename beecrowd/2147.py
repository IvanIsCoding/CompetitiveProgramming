# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2147
#!/usr/bin/env python
# -*- coding : utf-8 -*-
casos = int(input())
for caso_da_vez in range(casos):
    print("%.2f" % (float(len(input())) / 100.0))
