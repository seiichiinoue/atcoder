import itertools 
n = int(input())
perms = list(itertools.permutations(list(range(n))))
xy = []
for i in range(n):
    a, b = map(int, input().split())
    xy.append([a, b])
ans = 0
for perm in perms:
    length = len(perm)
    dist = 0;
    for i in range(length-1):
        ind = perm[i]
        ind1 = perm[i+1]
        dist += ((xy[ind][0]-xy[ind1][0])**2 + (xy[ind][1]-xy[ind1][1])**2)**(1/2)
    ans += dist
print(ans/len(perms))

        

