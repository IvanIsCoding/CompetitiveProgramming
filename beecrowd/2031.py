# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2031
#!/usr/bin/env python
# encoding : utf-8
def exibir(j1, j2):
    if j1 == "ataque":
        if j2 == "ataque":
            print("Aniquilacao mutua")
        elif j2 == "pedra":
            print("Jogador 1 venceu")
        else:
            print("Jogador 1 venceu")
    elif j1 == "pedra":
        if j2 == "ataque":
            print("Jogador 2 venceu")
        elif j2 == "pedra":
            print("Sem ganhador")
        else:
            print("Jogador 1 venceu")
    else:
        if j2 == "ataque":
            print("Jogador 2 venceu")
        elif j2 == "pedra":
            print("Jogador 2 venceu")
        else:
            print("Ambos venceram")


ordem = int(input())
for i in range(ordem):
    jogador1 = input()
    jogador2 = input()
    exibir(jogador1, jogador2)
