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

int n, m, ans;
vector<vector<int>> ABCD;
void dfs(vector<int> tmp, int pre) {
    if (tmp.size() == n) {
        int sum = 0;
        for (auto a : ABCD) if (tmp[a[1]] - tmp[a[0]] == a[2]) sum += a[3];
        chmax(ans, sum);
        return;
    }
    for (int i=pre; i<=m; ++i) {
        vector<int> tmp2 = tmp;
        tmp2.push_back(i);
        dfs(tmp2, i);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int q; cin >> n >> m >> q;
    rep(i, q) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        ABCD.push_back({--a, --b, c, d});
    }
    vector<int> tmp;
    dfs(tmp, 1);
    cout << ans << endl;
    // int n, m, q; cin >> n >> m >> q;
    // ll ans = 0;
    // vector<ll> A(q), B(q), C(q), D(q);
    // rep(i, q) {
    //     int a, b, c, d; 
    //     cin >> A[i] >> B[i] >> C[i] >> D[i];
    //     A[i]--; B[i]--;
    // }
    // vector<int> V(m);
    // rep(i, m) V[i] = i+1;
    // for (ll bit=1; bit < (1<<m); ++bit) {
    //     vector<int> tmp;
    //     ll score = 0;
    //     if (__builtin_popcount(bit) != n) continue;
    //     // cout <<  bitset<8>(bit) << endl;
    //     for (int i=0; i<m; ++i) {
    //         if (bit & (1<<i)) tmp.push_back(V[i]);
    //     }
    //     // rep(i, tmp.size()) cout << tmp[i] << " ";
    //     rep(i, q) {
    //         if (tmp[B[i]] - tmp[A[i]] == C[i]) score += D[i];
    //     }
    //     cout << score << endl;
    //     chmax(ans, score);
    // }
    // cout << ans << endl;
    return 0;
}