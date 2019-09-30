path = []
for _ in range(3):
    a, b = map(int, input().split(" "))
    path.append([a,b])


a = [0, 0, 0, 0]
for line in path:
    for d in line:
        a[d - 1] += 1

if sorted(a) == [1,1,2,2]:
    print('YES')
else:
    print('NO')