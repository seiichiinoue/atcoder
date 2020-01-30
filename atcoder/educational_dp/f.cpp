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
    string s, t; cin >> s >> t;
    int a = (int)s.size(), b = (int)t.size();
    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
    rep(i, a) {
        rep(j, b) {
            dp[i+1][j+1] = max({dp[i+1][j], dp[i][j+1]});
            if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
        }
    }
    int i = a, j = b;
    string ans = "";
    while (i>0 && j>0) {
        int lu, l, u;
        lu = dp[i-1][j-1];
        l = dp[i][j-1];
        u = dp[i-1][j];
        if (lu == dp[i][j]-1 && s[i-1] == t[j-1]) {
            ans = s[i-1] + ans;
            i--; j--;
        } else {
            if (l > u) j--;
            else i--;
        }
    }
    cout << ans << endl;
    return 0;
}