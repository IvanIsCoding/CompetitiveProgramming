# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1170
# -*- coding: utf-8 -*-
from math import ceil as teto
from math import log10 as log

log2 = lambda x: log(x) / log(2)
ordem = int(input())
for i in range(ordem):
    entradalinha = float(input())
    print("%d dias" % int(teto(log2(entradalinha))))
