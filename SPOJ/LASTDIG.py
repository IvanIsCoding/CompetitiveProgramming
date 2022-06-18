# Ivan Carvalho
# Solution to https://www.spoj.com/problems/LASTDIG/
t = int(input())
for i in range(t):
    a, b = [int(j) for j in input().split()]
    print(pow(a, b, 10))
