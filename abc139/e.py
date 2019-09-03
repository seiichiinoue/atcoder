n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
tmp = []

for i in range(n):
    for j in range(n-1):
        if i > a:
            i, a = a, i
        if (i, a) not in tmp:
            tmp.append((i,a))
        
