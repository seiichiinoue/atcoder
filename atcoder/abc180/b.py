n = int(input())
x = list(map(int, input().split()))
mnt = 0
yu = 0
che = 0
for xi in x:
    mnt += abs(xi)
    yu += xi * xi
    che = max(che, abs(xi))
print(mnt)
print(yu ** (0.5))
print(che)
