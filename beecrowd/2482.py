# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2482
#!/usr/bin/env python
# -*- coding : utf-8 -*-
linguas = int(input())
dicio = {}
for i in range(linguas):
    lingua = input()
    mensagem = input()
    dicio[lingua] = mensagem
nomes = int(input())
for i in range(nomes):
    nome = input()
    lingua = input()
    print(nome)
    print(dicio[lingua])
    print("")
