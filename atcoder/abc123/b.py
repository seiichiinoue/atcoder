a, b, c, d, e = [int(input()) for _ in range(5)]
l = [0 if str(i)[-1] == '0' else 10 - int(str(i)[-1]) for i in [a, b, c, d, e]]
ll = [a, b, c, d, e]
arr = []
for i in range(5):
    arr.append([l[i], ll[i]])
arr.sort()
ans = 0
for index, (i, j) in enumerate(arr):
    if index == len(arr) - 1:
        ans += j
    else:
        ans += i + j
print(ans)