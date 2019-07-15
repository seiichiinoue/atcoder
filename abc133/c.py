l, r = map(int, input().split())
mod = 2019
l %= mod
r %= mod
ans = l*r%mod
for i in range(l, r):
    for j in range(i+1, r+1):
        tmp = i*j%mod
        if ans > tmp:            
            ans = tmp
print(ans)