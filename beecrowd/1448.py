# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1448
#!/usr/bin/env python
# -*- coding : utf-8 -*-
casos = int(input())
for instancia in range(1, casos + 1):
    a = 0
    b = 0
    s1 = input()
    s2 = input()
    s3 = input()
    for i in range(len(s1)):
        a += s1[i] == s2[i]
        b += s1[i] == s3[i]
    if a == b:
        for i in range(len(s1)):
            if s1[i] == s2[i] and s1[i] != s3[i]:
                a += 1
                break
            if s1[i] == s3[i] and s1[i] != s2[i]:
                b += 1
                break
    if a > b:
        print("Instancia %d\ntime 1\n" % (instancia))
    elif a < b:
        print("Instancia %d\ntime 2\n" % (instancia))
    else:
        print("Instancia %d\nempate\n" % (instancia))
