import math; from statistics import mean; input()
l = list(map(int, input().split()))
print(math.ceil(sum(l) / sum([i != 0 for i in l])))