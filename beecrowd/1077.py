# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1077
#!/usr/bin/env python
# -*- coding : utf-8 -*-
casos = int(input())
for caso_davez in range(casos):
    entrada = input()
    valores = {"(": 1, "+": 2, "-": 2, "*": 3, "/": 3, "^": 4}
    resposta = []
    pilha = []
    for simbolo in entrada:
        if simbolo in "()+-*/^":
            if simbolo == "(":
                pilha.append(simbolo)
            elif simbolo == ")":
                while pilha[-1] != "(":
                    resposta.append(pilha.pop())
                pilha.pop()
            else:
                while True:
                    if len(pilha) == 0 or valores[simbolo] > valores[pilha[-1]]:
                        break
                    resposta.append(pilha.pop())
                pilha.append(simbolo)
        else:
            resposta.append(simbolo)
    while pilha:
        resposta.append(pilha.pop())
    print("".join(resposta))
