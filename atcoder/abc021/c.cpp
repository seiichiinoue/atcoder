// #include <bits/stdc++.h>
// using namespace std;
// #define INF 1e+9
// #define MAX_V 100
// #define rep(i,n) for(int i=0; i<n; ++i)
// typedef pair<int, int> P;

// struct edge {
//     int to;
//     int cost;
// };

// int V;
// vector<edge> G[MAX_V];
// int d[MAX_V];

// void dijkstra(int s) {
//     priority_queue<P, vector<P>, greater<P>> que;
//     fill(d, d+V, INF);
//     d[s] = 0;
//     que.push(P(0, s));

//     while(!que.empty()) {
//         P p = que.top(); que.pop();
//         int v = p.second;
//         if (d[v] < p.first) continue;
//         rep(i, G[v].size()) {
//             edge e = G[v][i];
//             if (d[e.to] > d[v] + e.cost) {
//                 d[e.to] = d[v] + e.cost;
//                 que.push(P(d[e.to],e.to));
//             }
//         }
//     }
// }

// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
//     cin >> V;
//     int a, b; cin >> a >> b;
//     a--; b--;
//     int m; cin >> m;
//     rep(i, m) {
//         int x, y;
//         cin >> x >> y;
//         x--; y--;
//         edge e = {y, 1};
//         G[x].push_back(e);
//         edge e1 = {x, 1};
//         G[y].push_back(e1);
//     }
//     int start = a;
//     dijkstra(start);
//     rep(i, V) {
//         cout << "cost from " << start << " to " << i << ": " << d[i] << endl; 
//     }

// }

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
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    int a, b; cin >> a >> b;
    a--; b--;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    rep(i, n) dp[i][i] = 0;
    int m; cin >> m;
    rep(i, m) {
        ll x, y; cin >> x >> y;
        dp[x-1][y-1] = 1;
        dp[y-1][x-1] = 1;
    }
    rep(i, n) rep(j, n) rep(k, n) {
        dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
    }
    vector<ll> ans(n, 0);
    ans[a] = 1;
    rep(i, n) rep(j, n) {
        if (dp[a][j] != i) continue;
        rep(k, n) {
            if (dp[a][k] == i+1 && dp[j][k] == 1) {
                ans[k] += ans[j];
                ans[k] %= MOD;
            }
        }
    }
    cout << ans[b] << endl;
    return 0;
}