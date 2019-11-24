#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main() {
    int n; cin >> n;
    vector<vector<ll>> G(n);
    vector<pair<int, int>> vp;
    for (int i=1; i<n; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        vp.push_back(make_pair(a, b));
    }
    int k=0;
    map<pair<int, int>, int> I;
    vector<int> cs(n, 0);
    vector<int> used(n, 0);
    queue<int> que;
    used[0] = 1;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        if (k<(int)G[v].size()) k=G[v].size();
        int cur = 1;
        for(int u : G[v]) {
            if(used[u]) continue;
            if(cur == cs[v]) cur++;
            cs[u] = I[make_pair(u, v)] = I[make_pair(v, u)] = cur++;
            used[u] = 1;
            que.emplace(u);
        }
    }
    cout << k << endl;
    for(auto p : vp){
        cout << I[p] << endl;
    }
}