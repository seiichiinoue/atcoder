# A, B = map(int, input().split())
# l = list(range(A,B))
# l += [B]
# l = [list("{:0>42}".format(format(i, 'b'))) for i in l]

# import numpy as np
# l = np.array(l)

# ans = ''
# for i in range(42):
#     if np.sum(l[:, i] == '1') % 2 == 1:
#         ans += '1'
#     else:
#         ans += '0'
# print(int(str(ans), 2))

A, B = map(int, input().split())
def xor(x):
    mod = x % 4
    if mod == 0:
        return x
    elif mod == 1:
        return 1
    elif mod == 2:
        return x ^ 1
    elif mod == 3:
        return 0
print(xor(A-1) ^ xor(B))