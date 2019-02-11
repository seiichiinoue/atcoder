s = int(input())

def f_n(i: int):
    if i % 2 == 0:
        return i / 2
    else:
        return 3 * i + 1


l = []
l.append(s)

for i in range(10000000000):
    # i + 2がm
    a = f_n(l[-1])

    if a in l:
        print(i + 2)
        break
    else:
        l.append(f_n(l[-1]))
