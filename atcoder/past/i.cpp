#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e18)
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
    int n, m; cin >> n >> m;
    vector<ll> sets(m), val(m);
    rep(i, m) {
        string tmp; cin >> tmp;
        cin >> val[i];
        int bit = 0;
        rep(j, n) bit |= (int)(tmp[j] == 'Y') << j;
        sets[i] = bit;
    }
    // rep(i, m) cout << sets[i] << " " << val[i] << endl;
    vector<vector<ll>> dp(m+1, vector<ll>((1<<n), INF));
    // rep(i, m) dp[i][0] = 0;
    dp[0][0] = 0;
    rep(i, m) {
        for (int bit=0; bit<(1<<n); ++bit) {
            chmin(dp[i+1][bit|sets[i]], dp[i][bit]+val[i]);
            dp[i+1][bit] = min(dp[i+1][bit], dp[i][bit]);
        }
    }
    ll ans = dp[m][(1<<n)-1] ==  INF ? -1 : dp[m][(1<<n)-1];
    cout << ans << endl;
    // rep(i, m+1) {
    //     rep(j, (1<<n)) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}