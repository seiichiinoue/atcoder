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
    string s; cin >> s;
    // for (int j=1; j<n; ++j) {
    //     int i = j-1, k = j+1;
    //     while (i > 0 && k < n) {

    //     }
    // }
    vector<int> r(n, 0), g(n, 0), b(n, 0);
    rep(i, n) {
        if (i==0) {
            if (s[i]=='R') r[i]++;
            if (s[i]=='G') g[i]++;
            if (s[i]=='B') b[i]++;
        }
        else {
            if (s[i]=='R') {
                r[i] = r[i-1]+1;
                g[i] = g[i-1];
                b[i] = b[i-1];
            }
            if (s[i]=='G') {
                r[i] = r[i-1];
                g[i] = g[i-1]+1;
                b[i] = b[i-1];
            }
            if (s[i]=='B') {
                r[i] = r[i-1];
                g[i] = g[i-1];
                b[i] = b[i-1]+1;
            }
        }
    }
    int ret = 0;
    for (int j=1; j<n; ++j) {
        int i=j-1, k=j+1;
        int ans = 0;
        if (s[j]=='R') {
            ans += g[i] * (b[n-1]-b[k-1]);
            ans += b[i] * (g[n-1]-g[k-1]);
            while(i>=0 && k<n) if ((s[i] == 'G' && s[k] == 'B') || s[i--] == 'B' && s[k++] == 'G') ans -= 1;
        }
        if (s[j]=='G') {
            ans += r[i] * (b[n-1]-b[k-1]);
            ans += b[i] * (r[n-1]-r[k-1]);
            while(i>=0 && k<n) if ((s[i] == 'R' && s[k] == 'B') || s[i--] == 'B' && s[k++] == 'R') ans -= 1;
        }
        if (s[j]=='B') {
            ans += g[i] * (r[n-1]-r[k-1]);
            ans += r[i] * (g[n-1]-g[k-1]);
            while(i>=0 && k<n) if ((s[i] == 'G' && s[k] == 'R') || s[i--] == 'R' && s[k++] == 'G') ans -= 1;
        }
        ret += ans;
    }
    cout << ret << endl;
    return 0;
}