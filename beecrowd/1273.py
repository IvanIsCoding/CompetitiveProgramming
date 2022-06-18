# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1273
#!/usr/bin/env python
# -*- coding : utf-8 -*-
verdade = False
while True:
    ordem = int(input())
    if ordem == 0:
        break
    if verdade:
        print("")
    else:
        verdade = True
    array = []
    for i in range(ordem):
        array.append(input())
    maximo = max([len(k) for k in array])
    for i in array:
        print("%s%s" % (" " * (maximo - len(i)), i))
