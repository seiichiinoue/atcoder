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
typedef pair<ll, ll> P;
constexpr ll  MOD = (1e9+7);
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
constexpr int lcm(int a, int b) { return a / gcd(a, b) * b; }

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll factorial(ll n, ll m=2) {
    // calculate n!
    m = max(2LL, m);
    ll rtn = 1;
    for (ll i=m; i<=n; i++) {
        rtn = (rtn * i) % MOD;
    }
    return rtn;
}
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];
    vector<vector<int>> cnt(h, vector<int>(w));
    // 縦方向
    rep(j, w) {
        vector<int> done(h);
        rep(i, h) {
            if (grid[i][j] == '#') continue;
            if (done[i]) continue;
            int offset = 0;
            while (i+offset<h) { 
                if (grid[i+offset][j] == '#') break;
                ++offset;
            }
            rep(k, offset) {
                cnt[i+k][j] += offset;
                done[i+k] = 1;
            }
        }
    }
    // 横
    rep(i, h) {
        vector<int> done(w);
        rep(j, w) {
            if (grid[i][j] == '#') continue;
            if (done[j]) continue;
            int offset = 0;
            while (j+offset<w) { 
                if (grid[i][j+offset] == '#') break;
                ++offset;
            }
            rep(k, offset) {
                cnt[i][j+k] += offset;
                done[j+k] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w) chmax(ans, cnt[i][j]-1);
    cout << ans << endl;
    return 0;
}