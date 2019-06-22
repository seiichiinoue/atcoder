n,l=map(int, input().split())
ll = sorted(list(map(lambda x: x+l-1, list(range(1,n+1)))))
tmp, ind = 10 ** 8, 10 ** 8
for i, ringo in enumerate(ll):
    if abs(ringo) < tmp:
        ind = i
        tmp = abs(ringo)
ll.pop(ind)
print(sum(ll))
    
