d = {}
for _ in range(int(input())):
  s = input()
  if s not in d.keys():
    d[s] = 0
  d[s] += 1
print(max([(v, k) for k, v in d.items()])[1])
  