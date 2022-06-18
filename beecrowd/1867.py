# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1867
#!/usr/bin/env python
# encoding : utf-8
def soma(x):
    numero = sum([int(i) for i in x])
    if numero <= 9:
        return numero
    else:
        return soma(str(numero))


while True:
    a, b = input().split(" ")
    if a == "0" and b == "0":
        break
    else:
        somaa = soma(a)
        somab = soma(b)
        if somaa == somab:
            print(0)
        elif somaa > somab:
            print(1)
        else:
            print(2)
