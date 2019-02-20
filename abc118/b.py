N, M = map(int, input().split())

l = []
for _ in range(M):
    l += [0]
aa=[]
for i in range(N):
    aa.append([int(i) for i in input().split()])
    aa[i].pop(0)

for line in aa:
    for i in line:
        l[i - 1] += 1

ans = 0
for index, s in enumerate(l):
    if s == N:
        ans += 1

print(ans)


