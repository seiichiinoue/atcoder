n, w = int(input()), list(map(int, input().split()))
l, r = 0, sum(w)
ans = 10 ** 8
for i in range(len(w)):
    l += w[i]
    r -= w[i]
    tmp = abs(l - r)
    if tmp < ans:
        ans = tmp
print(ans)