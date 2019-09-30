l, h = map(int, map(int, input().split()))
for _ in range(int(input())):
    i = int(input())
    if l <= i <= h:
        print(0)
    else:
        print(abs(i - l) if i < l else -1)