# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1222
#!/usr/bin/env python
# -*- coding : utf-8 -*-
while True:
    try:
        a, b, c = [int(i) for i in input().split()]
    except EOFError:
        break
    entrada = input().split()
    paginas = 1
    linha_da_vez = []
    linhas = 1
    for palavra in entrada:
        linha_da_vez.append(palavra)
        if len(" ".join(linha_da_vez)) > c:
            linha_da_vez = [palavra]
            linhas += 1
            if linhas > b:
                linhas = 1
                paginas += 1
    print(paginas)
