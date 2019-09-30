N = int(input())
util = [[int(i) for i in input().split()] for _ in range(N)]
"""
memo = [0 for _ in range(N + 1)]
def dp(i, u, rem_i):
    if i == N:
        return u
    elif i == 0:
        ret = max(dp(i + 1, u+util[i][0], 0), dp(i + 1, u+util[i][1], 1), dp(i + 1, util[i][2], 2))
    else:
        index = list({0, 1, 2} - {rem_i})
        ret = max(dp(i + 1, u+util[i][index[0]], index[0]), dp(i + 1, u+util[i][index[1]], index[1]))
    memo[i] = ret
    print(memo)
    return ret

print(dp(0, 0, 3))
"""

memo = [{} for i in range(N)]
for i in range(3):
    memo[-1][i] = util[-1][i]
for i in range(N-2, -1, -1):
    for j in range(3):
        memo[i][j] = util[i][j] + max(memo[i+1][k] for k in range(3) if j != k)
print(max(memo[0].values()))