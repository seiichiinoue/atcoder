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
    vector<ll> a(n);
    cin >> a[0];
    rep1(i, n-1) {
        ll tmp; cin >> tmp;
        a[i] = a[i-1] + tmp;
    }
    int c;
    ll diff = INF;
    rep(i, n) {
        int tmp = abs((a[n-1]-a[i]) - a[i]);
        if (tmp <= diff) {
            diff = tmp;
        } else {
            c = i-1;
            break;
        }
    }
    int c1;
    ll diff1 = INF;
    rep(i, c+1) {
        int tmp = abs((a[c]-a[i]) - a[i]);
        if (tmp <= diff) {
            diff1 = tmp;
        } else {
            c1 = i-1;
            break;
        }
    }
    int c2;
    ll diff2 = INF;
    for (int i=c+1; i<n; ++i) {
        int tmp = abs((a[n-1]-a[i]) - a[i]-a[c]);
        if (tmp <= diff2) {
            diff2 = tmp;
        } else {
            c2 = i-1;
            break;
        }
    }
    rep(i, n) cout << a[i] << " ";
    cout << endl;
    ll sum1 = a[c1], sum2 = a[c]-a[c1], sum3 = a[c2]-a[c], sum4 = a[n-1]-a[c2];
    cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
    cout << max({sum1, sum2, sum3, sum4}) - min({sum1, sum2, sum3, sum4}) << endl;
    return 0;
}