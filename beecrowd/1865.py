# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1865
#!/usr/bin/env python
# encoding : utf-8
ordem = int(input())
for i in range(ordem):
    a, b = input().split(" ")
    if a == "Thor":
        print("Y")
    else:
        print("N")
