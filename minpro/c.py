K, A, B = map(int, input().split())

K_ = K - (A - 1)
if (B - A) > 2:
	if K_ % 2 == 0:
		print((int(K_ / 2) * (B - A)) + A)
	else:
		print(int((K_ - 1) / 2) * (B - A) + 1 + A)
else:
	print(int(A + K_))