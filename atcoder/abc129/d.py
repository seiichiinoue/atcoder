import numpy as np
h,w=map(int, input().split())
arr=np.array([np.where(np.array(list(input())) == '.', 1, 0) for _ in range(h)])
#print(np.max(np.sum(arr, axis=0))+np.max(np.sum(arr, axis=1))-1)
