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

int main() {
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];
    vector<vector<int>> cnt(h, vector<int>(w));
    // left right
    rep(i, h) {
        vector<int> done(w);
        rep(j, w) {
            if (grid[i][j] == '#') continue;
            if (done[j]) continue;
            int l = 0;
            while (j+l < w) {
                if (grid[i][j+l] == '#') break;
                ++l;
            }
            rep(k, l) {
                cnt[i][j+k] += l;
                done[j+k] = 1;
            }
        }
    }
    // up down
    rep(j, w) {
        vector<int> done(h);
        rep(i, h) {
            if (grid[i][j] == '#') continue;
            if (done[i]) continue;
            int l = 0;
            while (i+l < h) {
                if (grid[i+l][j] == '#') break;
                ++l;
            }
            rep(k, l) {
                cnt[i+k][j] += l;
                done[i+k] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w) ans = max(ans, cnt[i][j]-1);
    cout << ans << endl;
    return 0;
}