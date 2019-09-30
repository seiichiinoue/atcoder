n = int(input())
l = list(map(int, input().split()))
s = sum(l)
if s % n != 0:
  print(-1)
  exit()
mean, ans = s // n, 0
for i in range(len(l) - 1):
    if l[i] < mean:
        l[i + 1] -= abs(l[i] - mean)
        ans += 1
    elif l[i] > mean:
        l[i + 1] += abs(l[i] - mean)
        ans += 1
print(ans)