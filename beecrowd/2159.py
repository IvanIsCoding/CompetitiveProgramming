# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2159
#!/usr/bin/env python
# -*- coding : utf-8 -*-
from math import log

n = int(input())
print("%.1f %.1f" % (n / log(n), 1.25506 * n / log(n)))
