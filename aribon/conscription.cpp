#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MAX_E (long long)1e5
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

struct UnionFind {
    /* N: 0-indexed array size */
    vector<int> par;
    
    UnionFind(int N) : par(N) {
        rep(i, N) par[i] = i;
    }
    
    int root(int x) {
        if (par[x]==x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx==ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

struct edge{ int u, v, cost; };

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal() {
    sort(es, es+E, comp);
    UnionFind tree(V);
    int res = 0;
    rep(i, E) {
        edge e = es[i];
        if (!tree.same(e.u, e.v)) {
            tree.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, r; cin >> n >> m >> r;
    E = r;
    V = (n+m);
    rep(i, r) {
        edge tmp; 
        int x, y, d; cin >> x >> y >> d;
        es[i] = (edge){x-1, n+y-1, -d};
    }
    cout << 10000 * (n+m) + kruskal() << endl;
    return 0;
}