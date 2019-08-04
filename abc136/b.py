n = int(input())
ans = 0
for i in range(n, 0, -1):
    if len(str(i)) % 2 == 1:
        ans += 1
print(ans)
