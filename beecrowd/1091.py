# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1091
#!/usr/bin/env python
# encoding : utf-8
while True:
    casos = int(input())
    if casos == 0:
        break
    else:
        xd, yd = [int(i) for i in input().split(" ")]
        for i in range(casos):
            x, y = [int(k) for k in input().split(" ")]
            if x == xd or y == yd:
                print("divisa")
            elif x > xd and y > yd:
                print("NE")
            elif x > xd and y < yd:
                print("SE")
            elif x < xd and y < yd:
                print("SO")
            else:
                print("NO")
