from itertools import product
n, m = map(int, input().split())
s = [list(map(int, input().split()))[1:] for _ in range(m)]
p = list(map(int, input().split()))

all_on = 0
for sp in product([0, 1], repeat=n):
    on = 0
    # 対象の電球を固定
    for i in range(m):
        cnt = 0
        # スイッチを固定
        for j in range(len(s[i])):
            if sp[s[i][j] - 1] == 1:
                cnt += 1
        if cnt % 2 == p[i]:
            on += 1
    if on == m:
        all_on += 1

print(all_on)
