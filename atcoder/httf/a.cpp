#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int n, m, b; cin >> n >> m >> b;
    vector<vector<char>> maze(n, vector<cahr>(n, '.'))
    int gy, gx; cin >> gy >> gx;
    maze[gy][gx] = 'G';
    unordered_map<string, int> dir;
    vector<P> robot_yx;
    vector<string> robot_dir;
    vector<P> block_yx;
    rep(i, m) {
        int y, x;
        string c;
        cin >> y >> x >> c;
        robot_yx.push_back(P(y, x));
        robot_dir.push_back(c);
    }
    rep(i, b) {
        int y, x;
        cin >> y >> x;
        maze[y][x] = '#';
    }
    return 0;
}