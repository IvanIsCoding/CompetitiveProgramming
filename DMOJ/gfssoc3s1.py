#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
n = int(raw_input())
resp = ""
pot = 0
while 2**pot <= n:
	resp = resp + "1"
	pot += 1
print resp