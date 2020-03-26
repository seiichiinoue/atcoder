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
    int a, b, n; cin >> a >> b >> n;
    vector<vector<int>> grid(a, vector<int>(b, 0));
    rep(i, n) { int x, y; cin >> x >> y; x--; y--; grid[x][y] = 1; }
    vector<vector<int>> dp(a, vector<int>(b, 0));
    // rep(i, a) dp[i][0] = 1;
    // rep(i, b) dp[0][i] = 1;
    dp[0][0] = 1;
    for (int i=0; i<b; ++i) {
        for (int j=0; j<a; ++j) {
            if (grid[j][i]) continue;
            if (j>0 && !grid[j-1][i]) dp[j][i] += dp[j-1][i];
            if (i>0 && !grid[j][i-1]) dp[j][i] += dp[j][i-1];
        }
    }

    cout << dp[a-1][b-1] << endl;
    return 0;
}