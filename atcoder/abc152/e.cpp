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
constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
constexpr ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// constexpr ll lcm(ll a, ll b) { return a * modinv(gcd(a, b), MOD) * b; }


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

vector<P> factorizer(ll n) {
    vector<P> facts;
    for (ll p=2; p*p<=n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        facts.push_back(P(p, num));
    }
    if (n != 1) facts.push_back(P(n, 1));
    return facts;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    unordered_map<ll, ll> max_exp;
    set<ll> base;
    rep(i, n) cin >> a[i];
    // ll lc = a[0];
    // for (int i=1; i<n; ++i) {
    //     lc = lcm(lc, a[i]);
    //     cout << lc << endl;
    // }
    rep(i, n) {
        vector<P> facts = factorizer(a[i]);
        for (auto prime_exp : facts) {
            base.insert(prime_exp.first);
            // mp[prime_exp.first] += prime_exp.second;
            chmax(max_exp[prime_exp.first], prime_exp.second);
        }
    }
    ll lc = 1;
    for (auto b : base) {
        lc *= modpow(b, max_exp[b]) % MOD;
        lc %= MOD;
    }
    ll ans = 0;
    rep(i, n) {
        ans += lc % MOD * modinv(a[i], MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}