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

bool compare_by_greater_y(pair<int,int>a, pair<int,int>b){
    if(a.second!=b.second) return a.second>b.second;
    else return a.first>b.first;
}

// 貪欲+2部グラフマッチング
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<P> r(n), b(n);
    vector<bool> rf(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        r[i] = P(x, y);
        rf[i] = 0;
    }
    sort(ALL(r), compare_by_greater_y);
    rep(i, n) {
        int x, y; cin >> x >> y;
        b[i] = P(x, y);
    }
    sort(ALL(b));
    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (!rf[j] && r[j].first<b[i].first && r[j].second<b[i].second) {
                ans++;
                rf[j] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}