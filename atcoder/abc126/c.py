n, k = map(int, input().split())
# n種類の得点が考えられる
ans = 0
for i in range(1, n+1):
    tmp = 1. / n
    point = i 
    while point < k:
        point *= 2
        tmp /= 2
    ans += tmp
print(ans)
