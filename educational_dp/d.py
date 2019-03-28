N, max_w = map(int, input().split())
W, V = [], []
for _ in range(N):
    w, v = map(int, input().split())
    W.append(w)
    V.append(v)

dp = [[-1 for _ in range(max_w + 1)] for _ in range(N + 1)]
def dfs(i, w):
    """i以降の商品からw以下となるように選んだ時の価値の総和"""
    if dp[i][w] >= 0:
        return dp[i][w]
    if i == N:
        ret = 0
    elif w < W[i]:
        ret = dfs(i + 1, w)
    else:
        ret = max(dfs(i + 1, w), dfs(i + 1, w - W[i]) + V[i])
    dp[i][w] = ret
    return ret

if __name__ == '__main__':
    print(dfs(0, max_w))