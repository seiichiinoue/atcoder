N = int(input())

l = []
for _ in range(N):
    l.append(int(input()))

import numpy as np

l = np.array(l)

turn = 0 # 偶数が私

for index, i in enumerate(l):
    mark = False
    if i%2!=0:
        mark = True
        l[index] -= 1
    if mark == True:
        turn += 1


# 全部偶数になった

turn += sum(list(l))
if turn % 2 == 0:
    print('first')
else:
    print('second') 
