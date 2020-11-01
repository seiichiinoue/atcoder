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
using namespace std;
using ll = long long;
struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}
template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

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
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        cnt[d]++;
    }

    if(n <= 2) {
        int num = stoi(s);
        int numm = -1;
        if(n == 2) {
            swap(s[0], s[1]);
            numm = stoi(s);
        }
        if(num % 8 == 0 || (numm != -1 && numm % 8 == 0)) {
            puts("Yes");
            return 0;
        }
        puts("No");
        return 0;
    }

    for (int x = 100; x < 1000; ++x) {
        if(x % 8 == 0) {
            vector<int> tmp(10, 0);
            int t = x;
            while(t > 0) {
                tmp[t % 10]++;
                t /= 10;
            }
            bool ok = true;
            for (int i = 0; i < 10; ++i) {
                if(cnt[i] < tmp[i]) ok = false;
            }
            if(ok) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}
