#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr ll  MOD = (1e9+7);
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

ll factorial(ll n, ll m=2) {
    // calculate nPm
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
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    // vector<int> A(n), B(n);
    vector<P> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(ALL(ab));
    // dp[i][j] : i番目までの料理でj分で食べれる料理の美味しさの合計の最大値
    vector<vector<ll>> dp(n+1, vector<ll>(t+1, 0));
    rep(i, n) {
        rep(j, t+1) {
            if (j - ab[i].first >= 0)
                dp[i+1][j] = max(dp[i][j], dp[i][j - ab[i].first] + ab[i].second);
            else
                dp[i+1][j] = dp[i][j];
        }
    }
    ll ans = 0;
    rep(i, n) chmax(ans, dp[i][t-1] + ab[i].second);
    cout << ans << endl;
    return 0;
}