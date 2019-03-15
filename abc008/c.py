N = int(input())
cs = [int(input()) for _ in range(N)]
p = 0.0
for target in cs:
  num_div = sum([target % r == 0 for r in cs]) - 1
  if num_div % 2 == 0:
    p += (num_div + 2) / (2 * num_div + 2)
  else:
    p += 1 / 2
print(p)
