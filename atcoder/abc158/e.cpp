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
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, p; cin >> n >> p;
    string s; cin >> s;
    ll res = 0;
    if (p==2 || p==5) {
        rep(i, n) {
            if ((s[i] - '0') % p == 0) res += i+1;
        }
    } else {
        vector<int> vec(n+1);
        rep(i, n) vec[i] = s[i] - '0';
        reverse(ALL(vec));
        vec[n] = 0;
        vector<int> mods(n);
        ll tmp = 0;
        rep(i, n) {
            tmp += (vec[i+1] % p * modpow(10, i, p) % p) % p;
            tmp %= p;
            mods[i] = tmp;
        }
        vector<int> cnt(p, 0);
        rep(i, n) {
            cnt[mods[i]]++;
            res += (mods[i] == 0 ? cnt[mods[i]] : cnt[mods[i]]-1);
        }
    }
    cout << res << endl;
}