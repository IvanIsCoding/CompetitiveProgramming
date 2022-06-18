# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1582
# encoding : utf-8
def mdc(x, y):
    p, q = sorted([x, y])
    if q % p == 0:
        return p
    else:
        return mdc(p, q % p)


def tripla(a, b, c):
    if a**2 + b**2 == c**2:
        if mdc(mdc(a, b), c) == 1:
            return "tripla pitagorica primitiva"
        else:
            return "tripla pitagorica"
    else:
        return "tripla"


while True:
    try:
        a, b, c = sorted([int(i) for i in input().split()])
        print(tripla(a, b, c))
    except EOFError:
        break
