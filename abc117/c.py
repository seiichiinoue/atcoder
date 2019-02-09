N, M = map(int, input().split(" "))
X = [int(n) for n in input().split(" ")]

X = sorted(X)

if len(X) <= N:
	print(0)

else:
	l = []
	for n in range(len(X)):
		if n != 0:
			l.append(abs(X[n - 1] - X[n]))

	ans = 0
	l = sorted(l, reverse=False)
	for i in range(M - N):
		ans += l.pop(0)

	print(ans)