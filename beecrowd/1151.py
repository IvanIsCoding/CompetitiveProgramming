# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1151
#!/usr/bin/env python
# encoding : utf-8
fib = [0, 1, 1]
maximo = int(input())
for i in range(3, maximo):
    fib.append(fib[i - 1] + fib[i - 2])
print(" ".join([str(k) for k in fib]))
