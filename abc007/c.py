R, C = map(int, input().split())
sx, sy = map(int, input().split())
sx -= 1
sy -= 1
gx, gy = map(int, input().split())
gx -= 1
gy -= 1
maze = [input() for _ in range(R)]
direction_x, direction_y = [1,0,-1,0], [0,1,0,-1]
maze_val = [[-1 for _ in range(C)] for _ in range(R)]
# 通ったところは.に変える / スタート地点からのコストを格納する

def solve():
    que = []
    que.append([sx, sy]) # スタート地点をプッシュ
    maze_val[sx][sy] = 0
    while True:
        x, y = que.pop(0) # キューから先頭を取り出す
        if (x, y) == (gx, gy):
            break
        for dx, dy in zip(direction_x, direction_y):
            # boundの判定とすでに通ったかどうかと通れるかどうかの判定
            vx, vy = x + dx, y + dy
            if (vx >= 0 and vx < R and vy >= 0 and vy < C) and maze_val[vx][vy] == -1 and maze[vx][vy] != '#':
                que.append([vx, vy]) # queにプッシュ
                maze_val[vx][vy] = maze_val[x][y] + 1 # コストを格納

    print(maze_val[gx][gy])

if __name__ == '__main__':
    solve()
