# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1789
#!/usr/bin/env python
# encoding : utf-8
while True:
    try:
        ordem = int(input())
        maximo = max([int(i) for i in input().split(" ")])
        if maximo < 10:
            print(1)
        elif maximo < 20:
            print(2)
        else:
            print(3)
    except EOFError:
        break
