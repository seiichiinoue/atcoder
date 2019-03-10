N, K = map(int, input().split())
R = sorted([int(i) for i in input().split()])

# memo = []
# def dfs(i=0, v=0, k=K):
#     if i == N or k == 0:
#         return v
#     else:
#         res = max(dfs(i+1, (v+R[i])/2., k-1), dfs(i+1, v, k))
#     return res

# print(dfs(0,0,K))

print(R)

rate=0
for i in range(K):
    rate=(rate+R[i-K])/2
print(rate)