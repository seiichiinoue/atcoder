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
    ll n, d, a; cin >> n >> d >> a;
    vector<P> x_h(n);
    rep(i, n) cin >> x_h[i].first >> x_h[i].second;
    sort(ALL(x_h));
    ll ans = 0, range_sum = 0;
    queue<P> bombs;
    rep(i, n) {
        while (!bombs.empty() && bombs.front().first < x_h[i].first) {
            range_sum -= bombs.front().second * a;
            bombs.pop();
        }
        x_h[i].second = max(0ll, x_h[i].second - range_sum);
        if (x_h[i].second <= 0) continue;
        ll cur = x_h[i].first + 2 * d;
        ll cur_need = (x_h[i].second + a - 1) / a;
        ans += cur_need;
        range_sum += cur_need * a;
        bombs.push(P(cur, cur_need));
    }
    cout << ans << endl;
}