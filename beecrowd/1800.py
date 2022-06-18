# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1800
#!/usr/bin/env python
# encoding : utf-8
q, e = [int(i) for i in input().split(" ")]
jaesteve = [int(k) for k in input().split(" ")]
for l in range(q):
    agora = int(input())
    if agora in jaesteve:
        print(0)
    else:
        print(1)
        jaesteve.append(agora)
