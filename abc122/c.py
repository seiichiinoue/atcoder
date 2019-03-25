N, Q = map(int, input().split())
S = input()
imosu = [0] * (N + 1)
for i in range(N):
    imosu[i + 1] = imosu[i] + (1 if S[i:i+2] == 'AC' else 0)
for i in range(Q):
    l, r = map(int, input().split())
    print(imosu[r-1]-imosu[l-1])
