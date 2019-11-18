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

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a / g * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<string> names(n);
    vector<ll> population(n);
    rep(i, n) {
        string a; int b;
        cin >> a >> b;
        names[i] = a;
        population[i] = b;
    }    
    ll sum = accumulate(ALL(population), 0LL);
    rep(i, n) {
        if ((double)population[i]/(double)sum > 0.5) {
            cout << names[i] << endl;
            return 0;
        }
    }
    cout << "atcoder" << endl;
    return 0;
}