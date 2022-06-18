# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2108
#!/usr/bin/env python
# -*- coding : utf-8 -*-
maior = 0
palavra = ""
while True:
    entrada = input().split()
    resposta = []
    if entrada == ["0"]:
        break
    for i in entrada:
        tamanho = len(i)
        if tamanho >= maior:
            maior = tamanho
            palavra = i
        resposta.append(str(tamanho))
    print("-".join(resposta))
print("\nThe biggest word: %s" % palavra)
