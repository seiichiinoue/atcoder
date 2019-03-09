N, M = map(int, input().split())
shop = []
for _ in range(N):
    a, b = map(int, input().split())
    shop.append([a,b])
shop.sort()

cur = 0
cur_v = 0
for a, b in shop:
    if cur + b > M:
        cur_v += (M - cur) * a
        break
    else:
        cur += b
        cur_v += a * b
print(cur_v)

