# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1176
#!/usr/bin/env python
ordem = int(input())
array = []
for i in range(ordem):
    array.append(int(input()))
fib = [0, 1, 1]
maximo = max(array)
for i in range(3, maximo + 1):
    fib.append(fib[i - 1] + fib[i - 2])
for number in array:
    print("Fib(%d) = %d" % (number, fib[number]))
