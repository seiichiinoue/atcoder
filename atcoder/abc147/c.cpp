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

int counter(int x) {
    if (x==0) return 0;
    return counter(x >> 1) + (x & 1);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n+1);
    vector<vector<int>> x(n+1, vector<int>(n+1));
    vector<vector<int>> y(n+1, vector<int>(n+1));
    rep1(i, n) {
        cin >> a[i];
        for(int j=1; j<=a[i]; ++j) cin >> x[i][j] >> y[i][j];
    }
    int ans = 0;
    for (int bits=1; bits<(1<<n); bits++) {
        bool ok = true;
        rep1(i, n) {
            if (!(bits & (1 << (i-1)))) continue;
            rep1(j, a[i]) {
                // 矛盾していないか
                if (((bits >> (x[i][j]-1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if (ok) chmax(ans, counter(bits));
    }
    cout << ans << endl;
    return 0;
}