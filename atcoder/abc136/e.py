n, k = map(int, input().split())
a = list(map(int, input().split()))

from functools import reduce

def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def gcds(*numbers):
    return reduce(gcd, numbers)


