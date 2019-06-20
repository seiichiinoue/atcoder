n, m = map(int, input().split())
INF = 1000000007
broken = [int(input()) for _ in range(m)]
dp = [0] * (n + 1)
for i in range(n + 1):
    if i == 0 or i == 1:
        if i not in broken:
            dp[i] = 1
    else:
        if i not in broken:
            dp[i] = dp[i - 1] + dp[i - 2]
print(dp[-1] % INF)