n = int(input())
p = list(map(int, input().split()))
cnt = 0
for i in range(n-2):
    a,b,c=p[i],p[i+1],p[i+2]
    if sorted([a,b,c]).index(b) == 1:
        cnt += 1
print(cnt) 