
N = int(input())

l = []
for _ in range(N):
    l.append(int(input()))

print('second' if all(l[i] % 2 == 0 for i in range(N)) else 'first')

