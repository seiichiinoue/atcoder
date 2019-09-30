n,m = map(int, input().split())
l = [[] for _ in range(n)]
for i in range(m):
    p,y = map(int, input().split())
    l[p-1].append((y, i))
ans = [None]*m
for i,pre in enumerate(l):
    pre.sort()
    for j,(a,b) in enumerate(pre):
        ans[b] = "{:0>6}{:0>6}".format(i+1,j+1)
print("\n".join(ans))