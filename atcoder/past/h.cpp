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
    int n; cin >> n;
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    vector<ll> odd;
    for (int j=1; j<n; j+=2) {
        odd.push_back(c[j]);
    }
    int q; cin >> q;
    ll min_c = INF, min_odd = INF;
    rep(i, n) {
        chmin(min_c, c[i]);
        if ((i+1)&1) chmin(min_odd, c[i]);
    }
    int odd_num = 0;
    rep1(i, n) if (i&1) odd_num++;
    ll sold_odd = 0, sold_even = 0;
    ll ans = 0;
    rep(i, q) {
        char num; cin >> num;
        if (num == '1') {
            ll x, a; cin >> x >> a;
            x--;
            if ((x+1)&1) {
                if (c[x]-sold_odd >= a) {
                    c[x] -= a;
                    chmin(min_odd, c[x]-sold_odd);
                    chmin(min_c, min_odd);
                    ans += a;
                } else continue;
            } else {
                if (c[x]-sold_even >= a) {
                    c[x] -= a;
                    chmin(min_c, c[x]-sold_even);
                    ans += a;
                } else continue;
            }
        } else if (num == '2') {
            ll a; cin >> a;
            if (min_odd >= a) {
                min_odd -= a;
                chmin(min_c, min_odd);
                sold_odd += a;
                ans += a * odd_num;
            }
        } else if (num == '3') {
            ll a; cin >> a;
            if (min_c >= a) {
                min_c -= a;
                min_odd -= a;
                sold_odd += a;
                sold_even += a;
                ans += a * n;
            }
        }
    }
    cout << ans << endl;
    return 0;
}