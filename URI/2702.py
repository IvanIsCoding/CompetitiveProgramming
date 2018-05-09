#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
a,b,c = [int(i) for i in raw_input().split()]
d,e,f = [int(i) for i in raw_input().split()]
print max(-a + d,0) + max(-b + e,0) + max(-c + f,0)
