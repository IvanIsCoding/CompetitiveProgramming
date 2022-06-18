# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1581
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
linguas = []
for i in range(ordem):
    subordem = int(input())
    sublinguas = []
    for j in range(subordem):
        sublinguas.append(input())
    linguas.append(sublinguas)
for array in linguas:
    lingua = array[0]
    if all([k == lingua for k in array]):
        print(lingua)
    else:
        print("ingles")
