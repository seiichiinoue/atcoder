from itertools import permutations
n = int(input())
l = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
l = l[:n]
ans = []
for v in permutations(l, n):
    ans.append("".join(list(v)))
print("\n".join(ans))