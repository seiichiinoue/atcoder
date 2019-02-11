import numpy as np
 
N, M = map(int, input().split(" "))
X = [int(n) for n in input().split(" ")]
 
X = sorted(X)
l = []
 
if len(X) <= N:
    print(0)
 
else:
    for n in range(len(X)):
        if n != 0:
            l.append(abs(X[n - 1] - X[n]))
 
    ans = 0
    for i in range(M - N):
        ans += l.pop(np.argmin(l))
        print(l)
 
    print(ans)