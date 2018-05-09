#!/usr/bin/env python2.7
# encoding : utf-8
a,b = [float(i) for i in raw_input().split(" ")]
print "%.2f%%" % (100*((b/a)-1.00))
