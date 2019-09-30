# import math
from functools import reduce
input()
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def gcds(*numbers):
    return reduce(gcd, numbers)
print(gcds(*[int(i) for i in input().split()]))