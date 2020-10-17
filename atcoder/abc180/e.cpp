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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll x[n], y[n], z[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<vector<ll>> cost(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cost[i][j] += abs(x[j] - x[i]);
            cost[i][j] += abs(y[j] - y[i]);
            cost[i][j] += max(0ll, z[j] - z[i]);
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(1 << 17, 1e18));
    dp[0][1] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 1);
    while(q.size()) {
        auto [cur, cities] = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
            int next = cities | (1 << i);
            if(dp[i][next] > dp[cur][cities] + cost[cur][i]) {
                dp[i][next] = dp[cur][cities] + cost[cur][i];
                q.emplace(i, next);
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[i][(1 << n) - 1] + cost[i][0]);
    }
    cout << ans << endl;
}