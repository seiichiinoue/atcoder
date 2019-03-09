N, M, C = map(int, input().split())
B = [int(i) for i in input().split()]
ans = 0
for _ in range(N):
    a = [int(i) for i in input().split()]
    s = 0
    for m in range(M):
        s += a[m] * B[m]
    s += C
    if s > 0:
        ans += 1
print(ans)

