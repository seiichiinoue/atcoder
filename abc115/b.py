n = int(input()); l=sorted([int(input()) for _ in range(n)])
print(int(sum(l)-l[-1]/2))