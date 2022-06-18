# Ivan Carvalho
# Solution to https://dmoj.ca/problem/inaho4
n = int(input())
a = [float(i) for i in input().split()]
b = [float(i) for i in input().split()]
total = 0
for i in range(len(a)):
    total += (b[i] - a[i]) * (b[i] - a[i])
print("%.6f" % (total**0.5))
