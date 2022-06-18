# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1983
#!/usr/bin/env python
# encoding : utf-8
array = []
ordem = int(input())
for i in range(ordem):
    a, b = [float(i) for i in input().split(" ")]
    array.append(a + b * 1j)
array.sort(key=lambda x: x.imag)
maximo = array[-1]
if maximo.imag >= 8:
    print(int(maximo.real))
else:
    print("Minimum note not reached")
