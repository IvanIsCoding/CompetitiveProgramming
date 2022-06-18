# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1593
#!/usr/bin/env python
# -*- coding : utf-8 -*-
casos = int(input())
for i in range(casos):
    print(str(bin(int(input()))).count("1"))
