# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1171
#!/usr/bin/env python
# -*- coding : utf-8 -*-
from collections import Counter

total = int(input())
contador = Counter()
for i in range(total):
    contador[int(input())] += 1
for a, b in sorted(contador.most_common()):
    print("%d aparece %d vez(es)" % (a, b))
