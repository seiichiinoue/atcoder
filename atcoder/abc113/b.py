import numpy; input(); t,a=map(int,input().split())
h=list(map(lambda x: abs(a-(t-int(x)*0.006)),input().split()))
print(numpy.argmin(h)+1)