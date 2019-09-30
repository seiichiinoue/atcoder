l = [int(input()) for _ in range(5)]
from itertools import combinations
p = list(combinations(l, 2))
k = int(input())
print('Yay!' if all([abs(p[i][0] - p[i][1]) <= k for i in range(len(p) - 1)]) else ':(')