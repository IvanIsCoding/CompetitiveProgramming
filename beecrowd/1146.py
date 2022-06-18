# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1146
#!/usr/bin/env python
# encoding : utf-8
while True:
    entrada = int(input())
    if entrada == 0:
        break
    else:
        print(" ".join([str(i) for i in range(1, entrada + 1)]))
