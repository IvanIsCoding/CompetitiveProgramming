# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1189
#!/usr/bin/env python
# encoding : utf-8
array = [[0 for j in range(12)] for k in range(12)]
operacao = input()
count = 0
for p in range(12):
    for k in range(12):
        e = float(input())
        if p + k <= 10 and p > k:
            array[p][k] = e
            count += 1
if operacao == "S":
    print("%.1f" % (sum([sum(x) for x in array])))
else:
    print("%.1f" % (sum([sum(x) for x in array]) / float(count)))
