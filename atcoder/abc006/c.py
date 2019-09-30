N, M = map(int, input().split())
a, b, c = [0, 0, 0]

def get_legnum(N, M, l):
    a, b, c = l
    max_leg = 0
    # process
    c = N
    max_leg = N * 4
    a = (max_leg - M) / 2
    c -= a
    return a, b, c

if N * 4 < M or N * 2 > M:
    print("-1 -1 -1")
    exit()

elif M % 2 == 0:
    a, b, c = get_legnum(N, M, [a, b, c])

elif M % 2 == 1:
    # 老人をセット
    b = 1
    M -= 3
    N -= 1
    # M % 2 == 0と同様
    a, b, c = get_legnum(N, M, [a, b, c])

print(int(a), int(b), int(c))