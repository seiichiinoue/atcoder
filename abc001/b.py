m = int(input())

import numpy as np
if m < 100:
    print('00')
elif m <= 5000:
    if m < 1000:
        print("".join(['0', str(int(m / 1000 * 10))]))
    else:
        print(int(m / 1000 * 10))
elif m <= 30000:
    print(int(m / 1000 + 50))
elif m <= 70000:
    print(int(((m / 1000 - 30) / 5) + 80))
else:
    print(89)