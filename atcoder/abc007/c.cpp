#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
    int R, C; cin >> R >> C;
    int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
    --sx; --sy; gx--; gy--;
    vector<string> c(R);
    vector<vector<double>> dist(R, vector<double>(C, -1));
    dist[sy][sx] = 0;
    for (int i = 0; i < R; ++i) cin >> c[i];
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    queue<P> q;
    q.push(P(sx, sy));
    while (q.size()) {
        int x, y;
        P top = q.front(); q.pop();
        x = top.first; y = top.second;
        if (x == gx && y == gy) {
            break;
        }
        for (int i=0; i<4; ++i) {
            int nx, ny; nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && dist[nx][ny] == -1 && c[nx][ny] != '#') {
                q.push(P(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    cout << dist[gx][gy] << endl;
}