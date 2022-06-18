# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2702
#!/usr/bin/env python
# -*- coding : utf-8 -*-
a, b, c = [int(i) for i in input().split()]
d, e, f = [int(i) for i in input().split()]
print(max(-a + d, 0) + max(-b + e, 0) + max(-c + f, 0))
