ans = 0
for _ in range(3):
  a, b = map(int, input().split())
  ans += a * b * 0.1
print(int(ans))