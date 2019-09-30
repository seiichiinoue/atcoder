a, b = map(int, input().split())
ans, tmp = 0, 1
while (tmp < b):
    ans += 1
    tmp -= 1
    tmp += a
print(ans)