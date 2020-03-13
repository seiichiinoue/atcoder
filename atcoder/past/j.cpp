#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define PI (acos(-1))
#define INF 1e+9
#define MAX_V 2500 * 2
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

struct edge {
    ll to;
    ll cost;
};

ll V;
vector<vector<vector<edge>>> G(50, vector<vector<edge>>(50));
ll d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(i, G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main() {
    int start = 0;
    int h, w; cin >> h >> w;
    V = h * w;
    ll E = h * w * (h-1) * (w-1);
    // rep(i, E) {
    //     int a, b, c;
    //     cin >> a >> b >> c;
    //     edge e = {b, c};
    //     G[a].push_back(e);
    // }
    vector<vector<ll>> graph(h, vector<ll>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> graph[i][j];
        }
    }
    vector<edge> i_from_cost;
    rep(i, h) {
        rep(j, w) {
            if (i==h) continue;
            G[i][j].push_back((edge){, graph[i][j]})
        }
    }
    dijkstra(start);
    rep(i, V) {
        if (d[i] != INF)
        cout << "cost from " << start << " to " << i << ": " << d[i] << endl; 
    }
}