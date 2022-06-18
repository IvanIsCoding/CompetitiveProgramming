# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2029
#!/usr/bin/env python
# encoding : utf-8
while True:
    try:
        volume = float(input())
        diametro = float(input())
        print("ALTURA = %.2f" % (4.0 * volume / (3.14 * (diametro**2))))
        print("AREA = %.2f" % (3.14 * (diametro**2) / 4.0))
    except EOFError:
        break
