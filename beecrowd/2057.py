# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2057
#!/usr/bin/env python
# encoding : utf-8
numero = sum([int(i) for i in input().split(" ")])
if numero < 0:
    print(numero + 24)
elif numero < 24:
    print(numero)
else:
    print(numero - 24)
