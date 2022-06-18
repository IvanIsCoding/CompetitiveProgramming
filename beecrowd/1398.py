# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1398
#!/usr/bin/env python
# -*- coding : utf-8 -*-
primo = 131071
entrada = []
while True:
    try:
        davez = input()
    except EOFError:
        break
    entrada.append(davez)
numeros = [i for i in "".join(entrada).split("#") if i != ""]
for i in numeros:
    if int(i, 2) % primo == 0:
        print("YES")
    else:
        print("NO")
