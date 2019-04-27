input()
a = list(map(int, input().split()))
cnt = sum([i < 0 for i in a])
s = [abs(i) for i in a]
if cnt % 2 == 0:
    print(sum(s))
else:
    print(sum(s) - min(s) * 2)