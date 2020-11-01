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

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for(auto& h : H) cin >> h;
    vector<int> W(M);
    for(auto& w : W) cin >> w;
    sort(H.begin(), H.end());
    vector<int> sum1((N + 1) / 2), sum2((N + 1) / 2);
    for(int i = 0; i + 1 < N; i += 2) sum1[i / 2 + 1] = sum1[i / 2] + H[i + 1] - H[i];
    for(int i = N - 2; i > 0; i -= 2) sum2[i / 2] = sum2[i / 2 + 1] + H[i + 1] - H[i];
    int ans = INF;
    for(int w : W){
        int x = lower_bound(H.begin(), H.end(), w) - H.begin();
        if(x & 1) x ^= 1;
        chmin(ans, sum1[x / 2] + sum2[x / 2] + abs(H[x] - w));
    }
    cout << ans << endl;
}