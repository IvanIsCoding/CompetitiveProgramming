# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1181
#!/usr/bin/env python
linha = int(input())
array = [[0 for j in range(12)] for k in range(12)]
operacao = input()
for p in range(12):
    for k in range(12):
        array[p][k] = float(input())
if operacao == "S":
    print("%.1f" % (sum(array[linha])))
else:
    print("%.1f" % (sum(array[linha]) / 12.0))
