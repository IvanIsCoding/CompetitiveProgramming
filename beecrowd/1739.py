# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1739
#!/usr/bin/env python
# -*- coding : utf-8 -*-
fibo = [1, 1]
tamanho = 0
lista = []
while tamanho < 60:
    proximo = fibo[-1] + fibo[-2]
    fibo.append(proximo)
    if proximo % 3 == 0 or "3" in str(proximo):
        tamanho += 1
        lista.append(proximo)
while True:
    try:
        a = int(input())
    except EOFError:
        break
    print(lista[a - 1])
