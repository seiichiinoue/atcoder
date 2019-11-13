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

int main() {
    ll n; cin >> n;
    vector<vector<ll>> to(n), cost(n);
    rep(i, n-1) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    vector<ll> ans(n, -1);
    queue<ll> q;
    ans[0] = 0;
    q.push(0);
    while (!q.empty()) {
        ll v = q.front(); q.pop();
        rep(i, to[v].size()) {
            ll u = to[v][i];
            ll w = cost[v][i];
            if (ans[u] != -1) continue;
            ans[u] = (ans[v] + w) % 2;
            q.push(u);
        }
    }
    rep(i, n) {
        cout << ans[i] << endl;
    }
    return 0;
}