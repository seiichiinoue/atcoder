n = int(input())
a = list(map(int, input().split()))

from functools import reduce
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
"""
def gcds(*numbers):
    return reduce(gcd, numbers)
"""
l = [0 for _ in range(n)]

for i in range(1, n):
    l[i] = gcd(l[i - 1], a[i - 1])
last_gcd = 0
for i in range(n - 2, -1, -1):
    last_gcd = gcd(last_gcd, a[i + 1])
    l[i] = gcd(last_gcd, l[i])
print(max(l))


