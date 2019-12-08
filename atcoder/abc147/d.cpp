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

template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;
    vector<Abel> dat;
    /* [1, n] */
    BIT(int n) : dat(n+1, UNITY_SUM) {}
    void init(int n) { dat.assign(n+1, UNITY_SUM); }
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i=a; i<(int)dat.size(); i+=i & -i)
            dat[i] = dat[i] + x;
    }
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i=a; i>0; i-=i & -i)
            res = res + dat[i];
        return res;
    }
    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b-1) - sum(a-1);
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> cnt(60, 0);
    rep(i, n) {
        rep(j, 60) {
            cnt[j] += (a[i] >> j) % 2;
        }
    }
    ll ans = 0;
    rep(b, 60) {
        ans += (1ll << b) % MOD * cnt[b] % MOD * (n - cnt[b]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}