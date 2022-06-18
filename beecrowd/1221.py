# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1221
#!/usr/bin/env python
# encoding : utf-8
def primo(x):
    return x == 2 or x % 2 != 0 and all([x % i for i in range(3, int(x**0.5) + 1, 2)])


ordem = int(input())
for j in range(ordem):
    i = int(input())
    if primo(i):
        print("Prime")
    else:
        print("Not Prime")
