# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1215
#!/usr/bin/env python
# -*- coding : utf-8 -*-
array = []


def funcao(x):
    if x.isalpha():
        return x
    else:
        return " "


while True:
    try:
        entrada = input().lower()
        array.append("".join([funcao(k) for k in entrada]))
    except EOFError:
        break
aquilo = set(" ".join(array).split(" "))
aquilo.remove("")
for i in sorted(aquilo, key=lambda x: (ord(x[0]), x)):
    print(i)
