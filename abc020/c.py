"""
from heapq import heappop,heappush
 
h,w,t = map(int,input().split())
S = [input() for i in range(h)]

for i in range(h):
    for j in range(w):
        if S[i][j] == 'S':
            start = i,j
        if S[i][j] == 'G':
            goal = i,j

dy = [0,1,0,-1]
dx = [1,0,-1,0]

def f(n):
    v = [[False]*w for i in range(h)]
    Q = []
    heappush(Q,(0,start))
    while Q!= []:
        c,(y,x) = heappop(Q)
        # 4方向調べる
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            if not 0 <= ny < h or not 0 <= nx < w:
                continue
            if v[ny][nx]:
                continue
            v[ny][nx] = True
            if S[ny][nx] == '#':
                nc = c+n
            else:
                nc = c+1
            if (ny,nx) == goal:
                return nc <= t
            heappush(Q,(nc,(ny,nx)))
    return False

low = 1
high = t
while low+1 < high:
    mid = (low+high) // 2
    if f(mid):
        low = mid
    else:
        high = mid

print(low)
"""


from heapq import heappop, heappush

h, w, t = map(int,input().split())
S = [input() for i in range(h)]

for i in range(h):
    for j in range(w):
        if S[i][j] == 'S':
            start = (i, j)
        if S[i][j] == 'G':
            goal = (i, j)

dy = [-1, 0, 0, 1]
dx = [0, 1, -1, 0]

def f(n):
    v = [[False] * w for _ in range(h)]
    Q = []
    heappush(Q, (0, start))
    while Q:
        c, (y, x) = heappop(Q)
        for i in range(4):
            cy, cx = y + dy[i], x + dx[i]
            if not 0 <= cy < h or not 0 <= cx < w:
                continue
            if v[cy][cx]:
                continue
            v[cy][cx] = True
            if S[cy][cx] == '#':
                cn = c + n
            else:
                cn = c + 1
            if (cy,cx) == goal:
                return cn <= t
            heappush(Q, (cn, (cy, cx)))
    return False

low = 1
high = t
while low + 1 < high:
    mid = (low + high) // 2
    if f(mid):
        low = mid
    else:
        high = mid
print(low)
