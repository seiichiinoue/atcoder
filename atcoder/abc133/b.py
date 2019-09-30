n, d = map(int, input().split())
X = []
for _ in range(n):
    l = list(map(int, input().split()))
    X.append(l)
mat = [[0 for _ in range(n)] for _ in range(n)]
import numpy as np
def f(a,b):
    return sum([(i-j)**2 for i, j in zip(a, b)])
for i in range(n):
    for j in range(i+1, n):
        mat[i][j] = np.sqrt(f(X[i], X[j]))
ans = 0
for i in range(n):
    for j in range(i+1, n):
        if mat[i][j].is_integer():
            ans +=1
print(ans)