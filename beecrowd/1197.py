# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1197
# -*- coding: utf-8 -*-
while True:
    try:
        a, b = [int(i) for i in input().split(" ")]
        print(2 * a * b)
    except EOFError:
        break
