import math 

N, P = map(int, input().split(" "))

def factorize(n):
    fct = list()
    base, exp = 2, 0
    while base * base <= n:
        while n % base == 0:
            n = n // base
            exp = exp + 1

        if exp > 0:
            fct.append((base, exp))

        base, exp = base + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct

fs = sorted(factorize(P), reverse=True)


ans = 1
for f in fs:
	if f[1] >= N:
		a = f[1] // N
		ans *= f[0] ** a

print(ans)

