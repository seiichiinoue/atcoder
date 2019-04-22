n = int(input())
l = list(map(int, input().split()))
s = sum(l)
if s % n != 0:
  print(-1)
  exit()
print(sum([abs(s/n - i) for i in l]))