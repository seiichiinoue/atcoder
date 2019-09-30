N,T = map(int, input().split())
l = []
for i in range(N):
  c, t = map(int, input().split())
  if not t > T:
    l.append([i+1, c])
if l == []:
    print('TLE'); exit()
l.sort(key=lambda x: x[1])
print(l[0][1])