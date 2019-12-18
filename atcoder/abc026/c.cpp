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

vector<vector<int>> buka(21);

int dfs(int i) {
    if (buka[i].size() == 0) return 1;
    ll ma = 0, mi = INF;
    rep(j, buka[i].size()) {
        ll p = dfs(buka[i][j]);
        chmin(mi, p); chmax(ma, p);
    }
    return mi + ma + 1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // 1~nの社員がいる, 高橋くんは1
    int n; cin >> n;
    // vector<vector<int> buka(n+1);
    // 社員番号i+1の上司の社員番号
    // vector<int> sarary(n+1);
    rep(i, n-1) {
        int a; cin >> a;
        buka[a].push_back(i+2);
    }
    cout << dfs(1) << endl;
    return 0;
}