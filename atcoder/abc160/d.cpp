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
    int n, x, y; cin >> n >> x >> y;
    x--; y--;
    vector<vector<int>> dist(n, vector<int>(n, 0));
    rep(i, n) rep(j, n) {
        if (i==j) dist[i][j] = 0;
        dist[i][j] = min({
            abs(j-i),
            abs(j-y) + abs(x-i) + 1,
            abs(j-x) + abs(y-i) + 1
        });
    }
    // rep1(i, n-1) {
    //     int ans = 0;
    //     rep(j, n) for(int k=j+1; k<n; ++k) {
    //         if (dist[j][k] == i) {
    //             ans++;
    //             // cout << j << " " << k << endl;
    //         }
    //     }
    //     cout << ans << endl;
    // }
    vector<int> ans(n);
    rep(i, n) for (int j=i+1; j<n; ++j) {
        ans[dist[i][j]]++;
    }
    rep1(i, n-1) cout << ans[i] << endl;
    return 0;
}