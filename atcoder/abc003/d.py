r, c = map(int, input().split())
x, y = map(int, input().split())
d, l = map(int, input().split())

def pas(n):
    if n < 1:
        return [1]
    p = pas(n - 1)
    return list(map(lambda a,b:a+b, [0]+p, p+[0]))

def pascal(n):
    l = []
    for x in range(n):
        l.append(pas(x))
    return l

if x * y == d + l:
    # X * Yの組み合わせを求める
    space = ((r - x) + 1) * ((c - y) + 1)
    # (x+y) C min(d,l) 組み合わせを求める
    com = pascal(x * y + 1)[x * y][min(d, l)]
    print(space * com % (10 ** 9 + 7))
else:
    print(100)
