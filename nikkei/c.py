import numpy as np

N = int(input())
l = [[], []]
for _ in range(N):
	a, b = map(int, input().split(" "))
	l[0].append(a)
	l[1].append(b)

ll = [sum([a,b]) for a, b in zip(l[0], l[1])]
ll = np.array(ll)

t = []
a = []
turn = True
for _ in range(N):
	if turn == True:
		index = np.argmax(ll)
		t.append(l[0][index])
		l[0].(index)
		l[1].(index)
		ll.(index)
		turn = False
		print(t)
	if turn == False:
		index = np.argmax(ll)
		a.append(l[1][index])
		l[0].(index)
		l[1].(index)
		ll.(index)
		turn = True
		print(a)

print(sum(t) - sum(a))
