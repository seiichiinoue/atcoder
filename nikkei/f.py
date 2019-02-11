N, K = map(int, input().split(" "))


d = {}
for n in range(N):
    c, v = map(int, input().split(" "))
    if c not in list(d.keys()):
        d[c] = []
        d[c].append(v)
    elif c in d.keys():
        d[c].append(v)


print(-1)
for n in range(N):
    # nこの宝石
    