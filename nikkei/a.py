
N, A, B = map(int, input().split(" "))

if A == B and A == N:
	print(A, A)
else:
	n = 0
	if A + B > N:
		n = A+B-N
	else:
		n = 0


	print(min(A, B), n)
