N=int(input())
l = [int(n) for n in input().split(" ")]

if max(l) < sum(l) - max(l):
    print('Yes')
else:
    print('No')