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
    int N, W; cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(N+1, vector<ll>(1e6+1, INF*2));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, 1e6+1) {
            // i番目までの品物で，価値の総和がj以下となる時の重さの総和の最小値
            // if (j+v[i]<=W)
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]], dp[i][j]+w[i]);
        }
    }
    int ans = 0;
    rep(i, N+1) rep(j, 1e6) {
        if (dp[i][j] > W) continue;
        chmax(ans, j);
    }
    cout << ans << endl;
    return 0;
}