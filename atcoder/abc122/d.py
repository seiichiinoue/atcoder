"""
n, mod = int(input()), 10 ** 9 + 7
memo = [{} for i in range(n+1)]
def check(l):
    for i in range(4):
        t = list(l)
        if i >= 1:
            t[i-1], t[i] = t[i], t[i-1] # 順序の入れ替え
        if ''.join(t).count('AGC') >= 1:
            return False
    return True

def dfs(cur, last3):
    if last3 in memo[cur]:
        return memo[cur][last3]
    if cur == n:
        return 1
    ret = 0
    for c in 'ACGT':
        if check(last3 + c):
            ret = (ret + dfs(cur + 1, last3[1:] + c)) % mod
    memo[cur][last3] = ret
    print(cur, memo)
    return ret

print(dfs(0, 'TTT'))
"""

n, mod = int(input()), 10 ** 9 + 7
memo = [[[[0 for _ in range(4)] for _ in range(4)] for _ in range(4)] for _ in range(n + 1)]
memo[0][3][3][3] = 1
for length in range(n):
    for s3 in range(4):  # 一番最後の文字
        for s2 in range(4):  # 最後から2番目の文字
            for s1 in range(4):  # 最後から3番目の文字
                # if memo[length][s3][s2][s1] == 0: continue
                # 新しく追加する文字
                for s4 in range(4):
                    # ダメな条件の時はcontinue
                    if s4 == 2 and s3 == 1 and s2 == 0: continue
                    if s4 == 2 and s3 == 0 and s2 == 1: continue
                    if s4 == 1 and s3 == 2 and s2 == 0: continue
                    if s4 == 2 and s3 == 1 and s1 == 0: continue
                    if s4 == 2 and s2 == 1 and s1 == 0: continue
                    
                    memo[length + 1][s4][s3][s2] += memo[length][s3][s2][s1]
                    memo[length + 1][s4][s3][s2] %= mod
ans = 0
for i in range(4):
    for j in range(4):
        for k in range(4):
            ans += memo[n][i][j][k]
            ans %= mod

print(ans)
