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
    string s; cin >> s;
    deque<char> dq;
    rep(i, s.size()) {
        dq.push_back(s[i]);
    }
    int q; cin >> q;
    int cnt_rev = 0;
    // reverseの回数が偶数の時は，元どおりなのでそのまま，奇数の時は逆側に追加すればよい
    rep(i, q) {
        int t; cin >> t;
        if (t == 1) {
            cnt_rev++;
            continue;
        } else {
            int f; cin >> f;
            char c; cin >> c;
            if (f == 1) {
                if (cnt_rev % 2 == 0) {
                    dq.emplace_front(c);
                } else {
                    dq.emplace_back(c);
                }
            } else {
                if (cnt_rev % 2 == 0) {
                    dq.emplace_back(c);
                } else {
                    dq.emplace_front(c);
                }
            }
        }
    }
    // if (cnt_rev % 2 != 0) reverse(ALL(s));
    if (cnt_rev % 2 == 0) {
        rep(i, dq.size()) {
            cout << dq[i];
        }
        cout << endl;
    } else {
        for (int i=dq.size()-1; i>=0; --i){
            cout << dq[i];
        }
        cout << endl;
    }

    return 0;
}