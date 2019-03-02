import bisect
A, B, Q = map(int, input().split())
INF = 10 ** 18
S = [-INF] + [int(input()) for _ in range(A)] + [INF]
T = [-INF] + [int(input()) for _ in range(B)] + [INF]

for q in range(Q):
    x = int(input())
    # return nearest index
    b, d = bisect.bisect_right(S, x), bisect.bisect_right(T, x)
    res = INF
    for s in [S[b-1], S[b]]:
        for t in [T[d-1], T[d]]:
            d1, d2 = abs(s - x) + abs(t - s), abs(t - x) + abs(s - t)
            res = min(res, d1, d2)
    print(res)

