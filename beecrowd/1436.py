# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1436
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())


def mediana(matriz):
    array = sorted(matriz)
    tamanho = len(array)
    if tamanho % 2 == 0:
        return int(array[tamanho / 2] + array[1 + tamanho / 2])
    else:
        return int(array[tamanho / 2])


for i in range(ordem):
    entrada = [int(k) for k in input().split(" ") if k != ""]
    print("Case %d: %d" % (i + 1, mediana(entrada[1:])))
