# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1140
#!/usr/bin/env python
# -*- coding : utf-8 -*-
while True:
    entrada = input()
    if entrada == "*":
        break
    if len(set([k[0].lower() for k in entrada.split()])) == 1:
        print("Y")
    else:
        print("N")
