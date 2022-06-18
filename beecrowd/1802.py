# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1802
#!/usr/bin/env python
# encoding : utf-8
entrada = []
for i in range(5):
    entrada.append(sorted([int(j) for j in input().split(" ")[1:]]))
ordem = int(input())
grupos = []
for a1 in entrada[0]:
    for a2 in entrada[1]:
        for a3 in entrada[2]:
            for a4 in entrada[3]:
                for a5 in entrada[4]:
                    grupos.append(a1 + a2 + a3 + a4 + a5)
print(sum(sorted(grupos)[::-1][:ordem]))
