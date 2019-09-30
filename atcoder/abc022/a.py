n, s, t = map(int, input().split())
w = int(input())
ans = s <= w <= t
for _ in range(n - 1):
    w += int(input())
    ans += s <= w <= t
print(ans)