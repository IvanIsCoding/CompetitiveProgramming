# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1198
#!/usr/bin/env python
# encoding : utf-8
while True:
    try:
        a, b = [int(i) for i in input().split(" ")]
        print(abs(a - b))
    except EOFError:
        break
