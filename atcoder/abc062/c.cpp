#include <bits/stdc++.h>
#define rep(i, n) for (long long i=0; i<n; ++i)
#define rep1(i, n) for (long long i=1; i<=n; ++i)
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
    ll h, w; cin >> h >> w;
    if (h % 3 == 0 || w % 3 == 0) puts("0");
    else {
        ll ans = min(h, w);
        rep1(i, h) {
            ll sa = i * w;
            ll sb = (h-i) * (w/2);
            ll sc = (h-i) * (w - (w/2));
            chmin(ans, max({sa, sb, sc}) - min({sa, sb, sc}));
        }
        rep1(i, w) {
            ll sa = i * h;
            ll sb = (w-i) * (h/2);
            ll sc = (w-i) * (h - (h/2));
            chmin(ans, max({sa, sb, sc}) - min({sa, sb, sc}));   
        }
        cout << ans << endl;
    }
    return 0;
}