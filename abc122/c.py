N, Q = map(int, input().split())
S = input()
for _ in range(Q):
    ans = 0
    l, r = map(int, input().split())
    tar = S[l-1:r]
    print(tar.count('AC'))