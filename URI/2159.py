# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2159
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
from math import log
n = int(raw_input())
print "%.1f %.1f" % (n/log(n),1.25506*n/log(n))
