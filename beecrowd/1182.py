# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1182
#!/usr/bin/env python
linha = int(input())
array = [[0 for j in range(12)] for k in range(12)]
operacao = input()
for p in range(12):
    for k in range(12):
        array[p][k] = float(input())
matriz = list(zip(*array))
if operacao == "S":
    print("%.1f" % (sum(matriz[linha])))
else:
    print("%.1f" % (sum(matriz[linha]) / 12.0))
