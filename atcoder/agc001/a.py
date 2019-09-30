N = int(input())
L = [int(i) for i in input().split()]
L.sort()
ans = 0
while len(L) != 0:
    ans += min(L.pop(0), L.pop(0))
print(ans)