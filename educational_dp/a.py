N = int(input())
H = [int(i) for i in input().split()]
"""
def dfs(cur, cost):
    if cur == N - 1: return cost
    elif cur < N - 2:
        return min(dfs(cur + 1, cost + abs(H[cur] - H[cur + 1])), dfs(cur + 2, cost + abs(H[cur] - H[cur + 2])))
    else:
        return dfs(cur + 1, cost + abs(H[cur] - H[cur + 1]))
print(dfs(0, 0))
"""

dp = [0] * N
dp[1] = abs(H[0] - H[1])
for i in range(2, N):
    dp[i] = min(dp[i-2] + abs(H[i]-H[i-2]), dp[i-1]+abs(H[i]-H[i-1]))
print(dp[-1])