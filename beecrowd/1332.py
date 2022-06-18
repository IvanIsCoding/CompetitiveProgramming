# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1332
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(ordem):
    entrada = input()
    if len(entrada) == 3:
        if len([l for k, l in enumerate([j for j in entrada]) if "one"[k] == l]) >= 2:
            print(1)
        elif len([l for k, l in enumerate([j for j in entrada]) if "two"[k] == l]) >= 2:
            print(2)
    else:
        print(3)
