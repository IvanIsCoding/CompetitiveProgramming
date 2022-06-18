# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1803
#!/usr/bin/env python
# encoding : utf-8
entrada = []
while True:
    try:
        entrada.append([i for i in input()])
    except EOFError:
        break
matring = [int("".join(k)) for k in zip(*entrada)]
f = matring[0]
l = matring[-1]
matring.pop(0)
matring.pop(-1)
caracteres = []
for i in matring:
    caracteres.append(chr((f * i + l) % 257))
print("".join(caracteres))
