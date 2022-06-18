# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2062
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
array = input().split()
for i in range(len(array)):
    t = array[i]
    if len(t) == 3:
        if "OB" in t:
            array[i] = "OBI"
        elif "UR" in t:
            array[i] = "URI"
print(" ".join(array))
