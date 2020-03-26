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
// constexpr ll  MOD = (1e9+7);
// constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// constexpr int lcm(int a, int b) { return a / gcd(a, b) * b; }

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
// ll factorial(ll n, ll m=2) {
//     // calculate n!
//     m = max(2LL, m);
//     ll rtn = 1;
//     for (ll i=m; i<=n; i++) {
//         rtn = (rtn * i) % MOD;
//     }
//     return rtn;
// }
// ll modinv(ll a, ll m) {
//     ll b = m, u = 1, v = 0;
//     while (b) {
//         ll t = a / b;
//         a -= t * b;
//         swap(a, b);
//         u -= t * v;
//         swap(u, v);
//     }
//     u %= m;
//     if (u < 0) u += m;
//     return u;
// }
// ll modpow(ll a, ll n) {
//     ll res = 1;
//     while (n > 0) {
//         if (n & 1)
//             res = res * a % MOD;
//         a = a * a % MOD;
//         n >>= 1;
//     }
//     return res;
// }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int cx, int cy, vector<vector<int> > &graph) {
    bool b = false;
    rep(i, 4) {
        if (graph[cx+dx[i]][cy+dy[i]]) b = true;
    }
    return b;
}

int ans = 0;
int n, m;

void dfs(int cnt, int cx, int cy, vector<vector<int> > &graph) {
    chmax(ans, cnt);
    graph[cx][cy] = 0;
    rep(i, 4) {
        if (cx+dx[i]<m && cx+dx[i]>=0 && cy+dy[i]<n && cy+dy[i]>=0 && graph[cx+dx[i]][cy+dy[i]]) {
            dfs(cnt+1, cx+dx[i], cy+dy[i], graph);
        }
    }
    graph[cx][cy] = 1;
    return;
}

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);
    for (;;) {
        ans = 0;
        cin >> m >> n;
        if (!m && !n) return 0;
        vector< vector<int> > graph(m, vector<int>(n));
        rep(i, m) rep(j, n) cin >> graph[i][j];
        rep(i, m) rep(j, n) if (graph[i][j]) dfs(1, i, j, graph);
        cout << ans << endl;
    }
    return 0;
}