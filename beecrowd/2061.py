# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2061
#!/usr/bin/env python
# encoding : utf-8
a, b = [int(i) for i in input().split(" ")]
abriu = 0
fechou = 0
for i in range(b):
    entrada = input()
    if entrada == "fechou":
        fechou += 1
    else:
        abriu += 1
print(a + fechou - abriu)
