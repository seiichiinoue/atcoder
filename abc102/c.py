input()
a = list(map(int, input().split()))
b = sorted([a[i]-i-1 for i in range(len(a))])
med=b[len(b)//2]
print(sum(list(map(abs,list(map(lambda x: x-med ,b))))))