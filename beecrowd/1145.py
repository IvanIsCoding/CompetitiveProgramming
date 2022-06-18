# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1145
#!/usr/bin/env python
a, b = [int(i) for i in input().split(" ")]
for i in range(1, b + 1, a):
    array = []
    for j in range(0, a):
        array.append(j + i)
    print(" ".join([str(f) for f in array if f <= b]))
