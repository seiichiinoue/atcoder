n = int(input())
a = list(map(int,input().split()))
b = [i - j for i, j in zip(a, list(range(1, len(a)+1)))]
b.sort()
if len(b) % 2 == 1:
    median = b[len(b) // 2]
else:
    m1, m2 = len(b) // 2, len(b) // 2 + 1
    median = (b[m1] + b[m2]) // 2
print(b)
print(sum([i - median for i in b]))