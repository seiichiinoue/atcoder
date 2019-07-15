n = int(input())
a = list(map(int, input().split()))
s = sum(a)
# まずX_1を求める
x_1 = s
for i in range(1,n,2):
    x_1 -= 2*a[i]
ans = [x_1]
for i in range(1, n):
    ans.append(2*a[i-1]-ans[i-1])
print(" ".join(list(map(str, ans))))