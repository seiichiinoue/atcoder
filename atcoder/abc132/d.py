"""
n,k = map(int, input().split())
from math import factorial
import numpy as np
for i in range(1,k+1):
    perm = factorial(n-k+1)/factorial((n-k+1)-i)
    tmp = np.ceil(k/i)
    a, b = int(k//tmp), int(k%tmp)
    perm /= (factorial(a)*factorial(b))
    print(int(perm)%(10**9+7))
"""

import math
N,K = (int(x) for x in input().split())
R = N - K
mod = 10**9 + 7
def fact(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
for i in range(1,K+1):
    ans = 0 if N - K + 1 < i else fact(R+1, i)*fact(K-1,i-1)
    print(int(ans)%mod)