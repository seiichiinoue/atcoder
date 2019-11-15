#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int xs[4] = {1, 0, -1, 0};
const int ys[4] = {0, 1, 0, -1};

int main() {
    int h, w; cin >> h >> w;
    int sx, sy, gx, gy;
    vector<vector<char>> maze(h, vector<char>(w));
    rep(i, h) rep(j, w) {
        char c; cin >> c;
        if (c=='S') {
            sx = j;
            sy = i;
        } else if (c=='G') {
            gx = j;
            gy = i;
        }
        maze[i][j] = c;
    }
    vector<vector<int>> cost(h, vector<int>(w, INF));
    queue<P> que;
    que.push(P(sx, sy));
    cost[sy][sx] = 0;
    while (que.size()) {
        P p = que.front(); que.pop();
        if (p.first == gx && p.second == gy) {
            break;
        }
        rep(i, 4) {
            int nx = p.first + xs[i], ny = p.second + ys[i];
            if (0 <= nx && nx < w && 0 <= ny && ny < h && maze[ny][nx] != '#' && cost[ny][nx] == INF) {
                que.push(P(nx, ny));
                cost[ny][nx] = cost[p.second][p.first] + 1;
            }
        }
    }
    cout << cost[gy][gx] << endl;

    return 0;
}