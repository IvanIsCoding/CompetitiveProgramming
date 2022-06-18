# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1457
#!/usr/bin/env python
# -*- coding : utf-8 -*-
tc = int(input())
for teste in range(tc):
    entrada = input()
    k = entrada.count("!")
    n = int(entrada.replace("!", ""))
    resposta = 1
    while n > 0:
        resposta *= n
        n -= k
    print(resposta)
