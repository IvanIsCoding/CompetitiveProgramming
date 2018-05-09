#!/usr/bin/env python2.7
# encoding : utf-8
while True:
	try:
		a,b = [int(i) for i in raw_input().split(" ")]
		print abs(a-b)
	except EOFError:
		break
