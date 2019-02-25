N = int(input())

ans = 0
for _ in range(N):
    x, u = input().split(" ")
    if u == 'JPY':
        ans += float(x)
    elif u == 'BTC':
        ans += float(x) * 380000
print(ans)