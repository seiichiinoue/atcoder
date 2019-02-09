
N, H, W = map(int, (input().split(" ")))

alloy = []
for _ in range(N):
	n,m = map(int, input().split(" "))
	alloy.append([n,m])

i = 0
for x, y in alloy:
	if x>=H and y>=W:
		i += 1


print(i)