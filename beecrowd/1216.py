# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1216
#!/usr/bin/env python
# encoding : utf-8
array = []
while True:
    try:
        nome = input()
        array.append(float(input()))
    except EOFError:
        break
print("%.1f" % (sum(array) / float(len(array))))
