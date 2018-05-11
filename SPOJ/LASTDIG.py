t = int(raw_input())
for i in xrange(t):
	a,b = [int(j) for j in raw_input().split()]
	print pow(a,b,10)